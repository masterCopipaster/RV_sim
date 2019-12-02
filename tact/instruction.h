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
		virtual int memory(proc_state& proc) = 0;
		virtual int writeback(proc_state& proc) = 0;
		bool active;
		//virtual ~instruction() = 0;
};

class instruction_R : public instruction
{
public:
	be_R_type_enc enc;
	instruction_R(uint32_t opcode);
	int memory(proc_state& proc);
	int writeback(proc_state& proc);
	int32_t rs1, rs2, rd, rdbuf;
	//virtual ~instruction_R() = 0;
};

class instruction_I : public instruction
{
public:
	be_I_type_enc enc;
	instruction_I(uint32_t opcode);
	int memory(proc_state& proc);
	int writeback(proc_state& proc);
	int32_t rs1, imm12, rd;
	//virtual ~instruction_I() = 0;
};

class instruction_S : public instruction
{
public:
	be_S_type_enc enc;
	instruction_S(uint32_t opcode);
	int memory(proc_state& proc);
	int writeback(proc_state& proc);
	int32_t rs1, rs2, imm12;
	//virtual ~instruction_S() = 0;
};

class instruction_U : public instruction
{
public:
	be_U_type_enc enc;
	instruction_U(uint32_t opcode);
	int memory(proc_state& proc);
	int writeback(proc_state& proc);
	int32_t imm20, rd;
	//virtual ~instruction_U() = 0;
};

class instruction_J : public instruction
{
public:
	be_J_type_enc enc;
	instruction_J(uint32_t opcode);
	int memory(proc_state& proc);
	int writeback(proc_state& proc);
	int32_t imm20, rd;
	//virtual ~instruction_J() = 0;
};

class instruction_B : public instruction
{
public:
	be_B_type_enc enc;
	instruction_B(uint32_t opcode);
	int memory(proc_state& proc);
	int writeback(proc_state& proc);
	int32_t rs1, rs2, imm12;
	//virtual ~instruction_B() = 0;
};

instruction* make_instruction(uint32_t opcode);

#define _RD rdbuf //proc.reg[rd] //proc.reg[enc.rd]
#define _RS1 proc.reg[rs1] //proc.reg[enc.rs1]
#define _RS2 proc.reg[rs2] //proc.reg[enc.rs2]
#define _PC proc.pc

#define _BIMM12 imm12 //B_type_imm_repair(enc)
#define _JIMM20 imm20 //J_type_imm_repair(enc)
#define _SIMM12 imm12 //S_type_imm_repair(enc)
#define _IIMM12 imm12 //enc.imm12
#define _UIMM20 imm20 //enc.imm20

#define __BIMM12 B_type_imm_repair(enc)
#define __JIMM20 J_type_imm_repair(enc)
#define __SIMM12 S_type_imm_repair(enc)
#define __IIMM12 enc.imm12
#define __UIMM20 enc.imm20

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

class ecall_instr : public instruction
{
	public:
	ecall_instr(uint32_t opcode) :instruction() {}
	int execute(proc_state& proc)
	{
		//['rs1', 'rs2', 'storeimm']
		printf("ecall\n");
		proc.pc += 4;
		return 0;
	}
};

#endif //INSTRUCTION_H
