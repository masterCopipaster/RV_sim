#include "memory.h"
#include <stdlib.h>

memory::memory()
{
	buf = (char*)malloc(DEFAULT_MEM_SIZE);
	size = DEFAULT_MEM_SIZE;
}

memory::memory(size_t _size)
{
	buf = (char*)malloc(_size);
	size = _size;
}

int8_t memory::read8(uint32_t addr)
{
	return *(int8_t*)(buf + addr);
}

int16_t memory::read16(uint32_t addr)
{
	return *(int16_t*)(buf + addr);
}

int32_t memory::read32(uint32_t addr)
{
	return *(int32_t*)(buf + addr);
}

void memory::write8(uint32_t addr, int8_t data)
{
	*(int8_t*)(buf + addr) = data;
}

void memory::write16(uint32_t addr, int16_t data)
{
	*(int16_t*)(buf + addr) = data;
}

void memory::write32(uint32_t addr, int32_t data)
{
	*(int32_t*)(buf + addr) = data;
}
