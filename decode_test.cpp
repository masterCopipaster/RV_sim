#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "instruction.h"


int main(int argc, char** argv)
{
	proc_state proc(10000);
	proc.printout();
	instruction* inst = new add_instr(0);
	((add_instr*)inst)->enc.rs1 = 1;
	((add_instr*)inst)->enc.rs2 = 2;
	((add_instr*)inst)->enc.rd = 0;
	//print_R_type(inst.enc);
	proc.reg[1] = 2;
	proc.reg[2] = 3;
	inst->execute(proc);
	proc.printout();
	return 0;
}

