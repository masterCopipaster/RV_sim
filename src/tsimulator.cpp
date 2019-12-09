#include "tsimulator.h"

int tsimulator::do_step()
{
	proc.stall = stall();
	proc.branch = 0;

	if (SF(writeback_ph, active))
	{
		writeback_ph->writeback(proc);
		printf("WRITEBACK PC: %X\n", writeback_ph->pcbuf);
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
		if (!(decode_ph = make_tinstruction(fetch_ph)) && fetch_ph)
		{
			decode_fault_counter++;
#ifdef DEBUG
			printf("wrong tinstruction code %X on addr %08X\n", opcode, proc.pc);
#endif
		}
		else if(decode_ph) decode_ph->pcbuf = fetch_addr;
		fetch_ph = proc.memif->read32(proc.pc);
		fetch_addr = proc.pc;
	}
	else execute_ph = 0;

	if (proc.branch)
	{
		if (decode_ph) delete decode_ph;
		decode_ph = 0;
		if (execute_ph) delete execute_ph;
		execute_ph = 0;
		fetch_ph = 0;
		proc.branch = 0;
	}

#ifdef ZERO_R0
	proc.reg[0] = 0;
#endif
	step_count++;
	if (decode_fault_counter > 1)
		return 1;
	return 0;
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
