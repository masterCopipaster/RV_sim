#include "cosimulator.h"

int cosimulator::do_step()
{
	if(fsim.do_step()) return 1;
	while( fsim.step_count > tsim.instr_count )
		if(tsim.do_step()) return 2;
	return 0;
}

void cosimulator::load_myhex(FILE* file)
{
	fsim.load_myhex(file);
	rewind(file);
	tsim.load_myhex(file);
}

cosimulator::cosimulator()
{
	fsim.proc.memif = new vmemory_pt();
	tsim.proc.memif = new vmemory_pt();
}

void cosimulator::printout()
{
	printf("===functional===\ninstruction count: %d\nstep count: %d\n", fsim.step_count, fsim.step_count);
	fsim.proc.printout();
	printf("======tact======\ninstruction count: %d\nstep count: %d\n", tsim.instr_count, tsim.step_count);
	tsim.proc.printout();	
}

bool cosimulator::compare()
{
	for(int i = 0; i < 32; i++)
		if(fsim.proc.reg[i] != tsim.proc.reg[i])
			return 1;
	return 0;
}

