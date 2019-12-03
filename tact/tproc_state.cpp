#include "tproc_state.h"

tproc_state::tproc_state(size_t  memsize)
{
	memif = new memory(memsize);
}

void tproc_state::printout()
{
	printf("stall: %d\tbranch: %d\n", stall, branch);
	printf("PC=%08X\n", pc);
	int i;
	for(i = 0; i < 32; i += 2)
		printf("R%d=%08X\tR%d=%08X\n", i, reg[i], i + 1, reg[i + 1]);
} 
