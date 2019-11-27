#include "vmemory.h"
#include <stdlib.h>

//vmemory::vmemory()
//{
//	buf = (char*)malloc(DEFAULT_MEM_SIZE);
//	size = DEFAULT_MEM_SIZE;
//}
//
//vmemory::vmemory(size_t _size)
//{
//	buf = (char*)malloc(_size);
//	size = _size;
//}

int8_t vmemory::read8(uint32_t addr)
{
	char* buf = getpage(addr);
	return *(int8_t*)(buf + INPAGE_ADDR(addr));
}

int16_t vmemory::read16(uint32_t addr)
{
	char* buf = getpage(addr);
	return *(int16_t*)(buf + INPAGE_ADDR(addr));
}

int32_t vmemory::read32(uint32_t addr)
{
	char* buf = getpage(addr);
	return *(int32_t*)(buf + INPAGE_ADDR(addr));
}

void vmemory::write8(uint32_t addr, int8_t data)
{
	char* buf = getpage(addr);
	*(int8_t*)(buf + INPAGE_ADDR(addr)) = data;
}

void vmemory::write16(uint32_t addr, int16_t data)
{
	char* buf = getpage(addr);
	*(int16_t*)(buf + INPAGE_ADDR(addr)) = data;
}

void vmemory::write32(uint32_t addr, int32_t data)
{
	char* buf = getpage(addr);
	*(int32_t*)(buf + INPAGE_ADDR(addr)) = data;
}

char* vmemory::getpage(uint32_t addr)
{
	auto it = pages.find(PAGENUM(addr));
	char* buf;
	if (it == pages.end())
	{
		buf = (char*)malloc(~PAGEMASK + 1);
		pages[PAGENUM(addr)] = buf;
	}
	else buf = it->second;
	return buf;
}