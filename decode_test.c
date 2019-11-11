#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "instruction.h"


int main(int argc, char** argv)
{
	uint32_t instr = atoi(argv[1]);
	print_I_type(instr);
	return 0;
}

