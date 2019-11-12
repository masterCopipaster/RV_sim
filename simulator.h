#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "instruction.h"
#include "proc_state.h"

class simulator
{
public:
	proc_state proc;
	int do_step();
	simulator(size_t memsize); 
	simulator(){};
};

#endif //_SIMULATOR_H
