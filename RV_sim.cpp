#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "simulator.h"


int main(int argc, char** argv)
{
	simulator sim(10000);
	sim.proc.memif->write32(0, 1200055);
	sim.proc.memif->write32(4, 99);
	while(!sim.do_step()) getchar();
	return 0;
}
