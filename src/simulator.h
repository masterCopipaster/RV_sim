#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#include "instruction.h"
#include "proc_state.h"

#include <unordered_map>

//#define DEBUG
#define ZERO_R0

struct icache_entity
{
	uint32_t addr;
	instruction* instr;
};

#define ICACHE_SIZE 256
#define ICACHE_IND(addr) ((addr >> 2) % ICACHE_SIZE)

class simulator
{
public:
	proc_state proc;
	unsigned long step_count = 0;
	bool use_icache = 0;
	int do_step();
	int do_step_perf();
	simulator(size_t memsize); 
	simulator(){};
	void load_myhex(FILE* file);
	unsigned long icache_miss = 0;
	unsigned long icache_hit = 0;
private:
	//std::unordered_map <uint32_t, instruction*> icache;
	icache_entity icache[ICACHE_SIZE] = {};
	instruction* get_instruction();
};

#endif //_SIMULATOR_H
