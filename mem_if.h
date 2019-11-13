#ifndef _MEM_IF_H
#define _MEM_IF_H
#include <stdint.h>

class mem_if
{
public:
	void virtual write32(uint32_t addr, int32_t data) = 0;
	void virtual write16(uint32_t addr, int16_t data) = 0;
	void virtual write8(uint32_t addr, int8_t data) = 0;

	int8_t virtual read8(uint32_t addr) = 0;
	int16_t virtual read16(uint32_t addr) = 0;
	int32_t virtual read32(uint32_t addr) = 0;

	//virtual ~mem_if();
};

#endif


