#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "simulator.h"
#include "vmemory.h"

 
int main(int argc, char** argv)
{
	simulator sim;
	sim.proc.memif = new vmemory();

	int i;
	char* filename = 0;
	bool wait = 0;
	bool debug = 0;
	bool usestdin = 0;
	FILE* file;

	for(i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-w")) wait = 1;
		else if (!strcmp(argv[i], "-d")) debug = 1;
		else if (!strcmp(argv[i], "-stdin")) usestdin = 1;
		else if (!strcmp(argv[i], "-icache")) sim.use_icache = 1;
		else filename = argv[i];
	}
	if (!usestdin)
	{
		if (!filename)
		{
			printf("please specify input filename\n");
			return 1;
		}

		printf("loading file %s\n", filename);
		file = fopen(filename, "rb");
	}
	else file = stdin;
	if(file) sim.load_myhex(file);
	else
	{
		printf("cannot open file\n");
		return 1;
	}

	while (!sim.do_step())
	{
		if(wait) if(getchar() == 'q') return 0;
		if(debug) sim.proc.printout();
	}
	printf("TOTAL INSTRUCTIONS: %d\n", sim.step_count);
	sim.proc.printout();
	return 0;
}
