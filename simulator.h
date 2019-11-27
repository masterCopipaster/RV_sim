#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "instruction.h"
#include "proc_state.h"

#include <unordered_map>

//#define DEBUG
#define ZERO_R0

class simulator
{
public:
	proc_state proc;
	unsigned long step_count = 0;
	bool use_icache = 0;
	std::unordered_map <uint32_t, instruction*> icache;
	int do_step();
	simulator(size_t memsize); 
	simulator(){};
	void load_myhex(FILE* file);
private:
	instruction* get_instruction();
};

#endif //_SIMULATOR_H
