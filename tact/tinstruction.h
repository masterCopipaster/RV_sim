#ifndef tinstruction_H
#define tinstruction_H

#include "decoder.h"
#include "tproc_state.h"

#include <stdint.h>

class tinstruction
{
	public:
		//uint32_t opcode;
		//uint32_t fixedmask;
		//uint32_t fixedvalue;
		virtual int execute(tproc_state& proc) = 0;
		virtual int memory(tproc_state& proc) = 0;
		virtual int writeback(tproc_state& proc) = 0;
		bool active = 1;
		uint32_t regs = 0, regd = 0;
		//virtual ~tinstruction() = 0;
};

class tinstruction_R : public tinstruction
{
public:
	be_R_type_enc enc;
	tinstruction_R(uint32_t opcode);
	int memory(tproc_state& proc);
	int writeback(tproc_state& proc);
	int32_t rs1, rs2, rd, rdbuf = 0;
	//virtual ~tinstruction_R() = 0;
};

class tinstruction_I : public tinstruction
{
public:
	be_I_type_enc enc;
	tinstruction_I(uint32_t opcode);
	int memory(tproc_state& proc);
	int writeback(tproc_state& proc);
	int32_t rs1, imm12, rd, rdbuf = 0;
	//virtual ~tinstruction_I() = 0;
};

class tinstruction_S : public tinstruction
{
public:
	be_S_type_enc enc;
	tinstruction_S(uint32_t opcode);
	int memory(tproc_state& proc);
	int writeback(tproc_state& proc);
	int32_t rs1, rs2, imm12;
	//virtual ~tinstruction_S() = 0;
};

class tinstruction_U : public tinstruction
{
public:
	be_U_type_enc enc;
	tinstruction_U(uint32_t opcode);
	int memory(tproc_state& proc);
	int writeback(tproc_state& proc);
	int32_t imm20, rd, rdbuf = 0;
	//virtual ~tinstruction_U() = 0;
};

class tinstruction_J : public tinstruction
{
public:
	be_J_type_enc enc;
	tinstruction_J(uint32_t opcode);
	int memory(tproc_state& proc);
	int writeback(tproc_state& proc);
	int32_t imm20, rd, rdbuf = 0;
	//virtual ~tinstruction_J() = 0;
};

class tinstruction_B : public tinstruction
{
public:
	be_B_type_enc enc;
	tinstruction_B(uint32_t opcode);
	int memory(tproc_state& proc);
	int writeback(tproc_state& proc);
	int32_t rs1, rs2, imm12;
	//virtual ~tinstruction_B() = 0;
};

tinstruction* make_instruction(uint32_t opcode);

#define _RD rdbuf //proc.reg[rd] //proc.reg[enc.rd]
#define _RS1 proc.reg[rs1] //proc.reg[enc.rs1]
#define _RS2 proc.reg[rs2] //proc.reg[enc.rs2]
#define _PC proc.pc
#define _BR proc.branch
#define _STALL proc.stall
#define _SETBR _BR = 1;
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
class add : public tinstruction <be_R_type_enc>
{
	public:
	int execute(tproc_state& proc)
	{
		proc.reg[enc.rd] = proc.reg[enc.rs1] + proc.reg[enc.rs2];
		proc.pc+=4;
		return 0;
	}
};
*/

#include "instr_autogen.h"

class ecall_instr : public tinstruction
{
	public:
	ecall_instr(uint32_t opcode) :tinstruction() {}
	int execute(tproc_state& proc)
	{
		//['rs1', 'rs2', 'storeimm']
		printf("ecall\n");
		proc.pc += 4;
		return 0;
	}
	int memory(tproc_state& proc) { return 0; }
	int writeback(tproc_state& proc) { return 0; }
};

#endif //tinstruction_H
