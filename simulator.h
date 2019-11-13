#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "instruction.h"
#include "proc_state.h"

//#define DEBUG
#define ZERO_R0

class simulator
{
public:
	proc_state proc;
	int do_step();
	simulator(size_t memsize); 
	simulator(){};
	void load_myhex(FILE* file);
};

#endif //_SIMULATOR_H
