#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "simulator.h"


int main(int argc, char** argv)
{
	simulator sim(10000);
	//sim.proc.memif->write32(0, 19 | (1 << 20) | (1 << 7) | (1 << 15));
	//sim.proc.memif->write32(4, 103 | (-4 << 20));
	//sim.proc.memif->write32(8, 103 | (-8 << 20));
	//printf("0	%X\n4	%X\n8	%X\n", 19 | (1 << 20) | (1 << 7) | (1 << 15), 103 | (-4 << 20), 103 | (-8 << 20));

	FILE* file;
	if(!(argv[1] && (file = fopen(argv[1], "rb"))))
		file = fopen("basic_loop_test.txt", "rb");
	if(file) sim.load_myhex(file);

	while (!sim.do_step() && getchar() != 'q');
		//getchar()
	sim.proc.printout();
	return 0;
}
