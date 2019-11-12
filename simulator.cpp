#include "simulator.h"

int simulator::do_step()
{
	uint32_t opcode = proc.memif->read32(proc.pc);
	instruction* inst = make_instruction(opcode);
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
	delete inst;
	return 0;
}

simulator::simulator(size_t memsize)
{
	proc = proc_state(memsize);
}