#include "tsimulator.h"

int tsimulator::do_step()
{
	proc.stall = stall();
	proc.branch = 0;

	if (SF(writeback_ph, active))
	{
		writeback_ph->writeback(proc);
		instr_count++;
	}
	if(writeback_ph) delete writeback_ph;

	if (SF(memory_ph, active))
	{
		memory_ph->memory(proc);	
	}
	writeback_ph = memory_ph;

	if (SF(execute_ph, active))
	{
		execute_ph->execute(proc);
	}
	memory_ph = execute_ph;

	if (!proc.stall)
	{
		execute_ph = decode_ph;
		if (!(decode_ph = make_instruction(fetch_ph)))
		{
			decode_fault_counter++;
#ifdef DEBUG
			printf("wrong tinstruction code %X on addr %08X\n", opcode, proc.pc);
#endif
		}
		fetch_ph = proc.memif->read32(proc.pc);
	}
	else execute_ph = 0;

	if (proc.branch)
	{
		decode_ph = 0;
		execute_ph = 0;
		proc.branch = 0;
	}

#ifdef ZERO_R0
	proc.reg[0] = 0;
#endif
	step_count++;
	if (decode_fault_counter > 1) return 1;
	return 0;
	/*tinstruction* inst;
	if(use_icache)
		inst = get_instruction();
	else
	{
		uint32_t opcode = proc.memif->read32(proc.pc);
		inst = make_instruction(opcode);
	}

	if(!inst) 
	{
#ifdef DEBUG
		printf("wrong tinstruction code %X on addr %08X\n", opcode, proc.pc);
#endif
	return 1;
	}
	inst->execute(proc);
	
#ifdef ZERO_R0
	proc.reg[0] = 0;
#endif

#ifdef DEBUG
	proc.printout();
#endif
	if(!use_icache) delete inst;
	step_count++;
	return 0;*/
}

tsimulator::tsimulator(size_t memsize)
{
	proc = tproc_state(memsize);
}


void tsimulator::load_myhex(FILE* file)
{
	uint32_t addr, opcode;
	fscanf(file, "EP: %X\n", &proc.pc);
	while (fscanf(file, "%X %X\n", &addr, &opcode) == 2)
	{
		proc.memif->write32(addr, opcode);
	}
}

bool tsimulator::stall()
{
	return (SF(decode_ph, regs) & SF(execute_ph, regd)) || (SF(decode_ph, regs) & SF(memory_ph, regd)) || (SF(decode_ph, regs) & SF(writeback_ph, regd));
}

tinstruction* tsimulator::get_instruction()
{
	/*auto it = icache.find(proc.pc);
	tinstruction* instr = 0;
	if (it == icache.end())
	{
		instr = make_instruction(proc.memif->read32(proc.pc));
		icache[proc.pc] = instr;
	}
	else instr = it->second;*/
	int ind = ICACHE_IND(proc.pc);
	if(icache[ind].addr == proc.pc) 
	{
		icache_hit++;
		return icache[ind].instr;
	}
	else
	{
		if(icache[ind].instr) delete icache[ind].instr;
		icache[ind].instr = make_instruction(proc.memif->read32(proc.pc));
		icache[ind].addr = proc.pc;
		icache_miss++;
	}
	return icache[ind].instr;
}
