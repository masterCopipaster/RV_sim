#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "simulator.h"


int main(int argc, char** argv)
{
	simulator sim(10000);

	FILE* file;
	if(!(argv[1] && (file = fopen(argv[1], "rb"))))
		file = fopen("basic_loop_test.txt", "rb");
	if(file) sim.load_myhex(file);

	while (!sim.do_step() && getchar() != 'q');
		//getchar()
	sim.proc.printout();
	return 0;
}
