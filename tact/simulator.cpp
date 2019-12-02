#include "simulator.h"

int simulator::do_step()
{
	instruction* inst;
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
		printf("wrong instruction code %X on addr %08X\n", opcode, proc.pc);
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
	return 0;
}

simulator::simulator(size_t memsize)
{
	proc = proc_state(memsize);
}


void simulator::load_myhex(FILE* file)
{
	uint32_t addr, opcode;
	fscanf(file, "EP: %X\n", &proc.pc);
	while (fscanf(file, "%X %X\n", &addr, &opcode) == 2)
	{
		proc.memif->write32(addr, opcode);
	}
}

instruction* simulator::get_instruction()
{
	/*auto it = icache.find(proc.pc);
	instruction* instr = 0;
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
