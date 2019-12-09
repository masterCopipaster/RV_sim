#include "proc_state.h"

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
} 
