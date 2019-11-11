#include "instruction.h"

instruction_R::instruction_R(uint32_t opcode)
{
	enc = *(be_R_type_enc*)&opcode;
}

instruction_I::instruction_I(uint32_t opcode)
{
	enc = *(be_I_type_enc*)&opcode;
}

instruction_S::instruction_S(uint32_t opcode)
{
	enc = *(be_S_type_enc*)&opcode;
}

instruction_U::instruction_U(uint32_t opcode)
{
	enc = *(be_U_type_enc*)&opcode;
}

instruction_J::instruction_J(uint32_t opcode)
{
	enc = *(be_J_type_enc*)&opcode;
}

instruction_B::instruction_B(uint32_t opcode)
{
	enc = *(be_B_type_enc*)&opcode;
}

