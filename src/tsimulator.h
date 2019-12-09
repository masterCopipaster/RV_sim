#ifndef _TSIMULATOR_H
#define _TSIMULATOR_H

#include "tinstruction.h"
#include "tproc_state.h"

#include <unordered_map>

//#define DEBUG
#define ZERO_R0

#define SF(str, field) (str ? str->field : 0)

class tsimulator
{
public:
	tproc_state proc;
	unsigned long step_count = 0;
	unsigned long instr_count = 0;
	bool use_icache = 0;
	int do_step();
	tsimulator(size_t memsize); 
	tsimulator(){};
	void load_myhex(FILE* file);
	unsigned long icache_miss = 0;
	unsigned long icache_hit = 0;

	//pipeline phases
	uint32_t fetch_ph = 0;
	uint32_t fetch_addr = 0;
	tinstruction* decode_ph = 0;
	tinstruction* execute_ph = 0;
	tinstruction* memory_ph = 0;
	tinstruction* writeback_ph = 0;
	int decode_fault_counter = 0;
private:
	bool stall();
};

#endif //_TSIMULATOR_H
