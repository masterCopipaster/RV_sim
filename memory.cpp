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

INT8 memory::read8(UINT32 addr)
{
	return *(INT8*)(buf + addr);
}

INT16 memory::read16(UINT32 addr)
{
	return *(INT16*)(buf + addr);
}

INT32 memory::read32(UINT32 addr)
{
	return *(INT32*)(buf + addr);
}

void memory::write8(UINT32 addr, INT8 data)
{
	*(INT8*)(buf + addr) = data;
}

void memory::write16(UINT32 addr, INT16 data)
{
	*(INT16*)(buf + addr) = data;
}

void memory::write32(UINT32 addr, INT32 data)
{
	*(INT32*)(buf + addr) = data;
}
