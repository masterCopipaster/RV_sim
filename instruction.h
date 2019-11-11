#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "decoder.h"
#include "proc_state.h"

template <class enc_type> class instruction
{
	public:
		enc_type enc;
		virtual int execute(proc_state& proc) = 0;
};
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
