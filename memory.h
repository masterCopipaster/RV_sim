#ifndef _MEMORY_H
#define _MEMORY_H

#include <stdint.h>
#include <stddef.h>

#include "mem_if.h"

#define DEFAULT_MEM_SIZE 0x10000

class memory : public mem_if
{
public:
	void write32(uint32_t addr, int32_t data);
	void write16(uint32_t addr, int16_t data);
	void write8(uint32_t addr, int8_t data);

	int8_t read8(uint32_t addr);
	int16_t read16(uint32_t addr);
	int32_t read32(uint32_t addr);

	memory(size_t size);
	memory();

private:
	char* buf;
	size_t size;
};

#endif
