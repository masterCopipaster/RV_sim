#ifndef _PROCSTATE_H
#define _PROCSTATE_H

#include "memory.h"
#include "stdio.h"

class proc_state
{
	public:
		mem_if* memif = 0;
		uint32_t pc = 0;
		int32_t reg[32] = {};

		bool branch = 0;
		bool stall = 0;
		
		void printout();
		proc_state(size_t  memsize);
		proc_state(){}
	private:
};
/*
proc_state::proc_state(size_t  memsize)
{
	memif = new memory(memsize);
}

void proc_state::printout()
{
	printf("PC=%08X\n", pc);
	int i;
	for(i = 0; i < 32; i += 2)
		printf("R%d=%08X\tR%d=%08X\n", i, reg[i], i + 1, reg[i + 1]);
} */

#endif //PROCSTATE_H
