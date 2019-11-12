#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "decoder.h"
#include "proc_state.h"

#include <stdint.h>

class instruction
{
	public:
		//uint32_t opcode;
		//uint32_t fixedmask;
		//uint32_t fixedvalue;
		virtual int execute(proc_state& proc) = 0;
		//virtual ~instruction() = 0;
};

class instruction_R : public instruction
{
public:
	be_R_type_enc enc;
	instruction_R(uint32_t opcode);
	//virtual ~instruction_R() = 0;
};

class instruction_I : public instruction
{
public:
	be_I_type_enc enc;
	instruction_I(uint32_t opcode);
	//virtual ~instruction_I() = 0;
};

class instruction_S : public instruction
{
public:
	be_S_type_enc enc;
	instruction_S(uint32_t opcode);
	//virtual ~instruction_S() = 0;
};

class instruction_U : public instruction
{
public:
	be_U_type_enc enc;
	instruction_U(uint32_t opcode);
	//virtual ~instruction_U() = 0;
};

class instruction_J : public instruction
{
public:
	be_J_type_enc enc;
	instruction_J(uint32_t opcode);
	//virtual ~instruction_J() = 0;
};

class instruction_B : public instruction
{
public:
	be_B_type_enc enc;
	instruction_B(uint32_t opcode);
	//virtual ~instruction_B() = 0;
};

instruction* make_instruction(uint32_t opcode);

#define _RD proc.reg[enc.rd]
#define _RS1 proc.reg[enc.rs1]
#define _RS2 proc.reg[enc.rs2]

/*
class add : public instruction <be_R_type_enc>
{
	public:
	int execute(proc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
		proc.pc+=4;
		return 0;
	}
};
*/

#include "instr_autogen.h"

#endif //INSTRUCTION_H
