#ifndef _VMEMORY_H
#define _VMEMORY_H

#include <unordered_map>
#include <stdint.h>
#include <stddef.h>


#include "mem_if.h"

#define PAGEMASK  0xFFFFF000
#define PAGENUM(addr)  (PAGEMASK & addr)
#define PAGENUM_OFFS(addr) (addr / (~PAGEMASK + 1))
#define INPAGE_ADDR(addr)	(~PAGEMASK & addr)	

class vmemory : public mem_if
{
public:
	void write32(uint32_t addr, int32_t data);
	void write16(uint32_t addr, int16_t data);
	void write8(uint32_t addr, int8_t data);

	int8_t read8(uint32_t addr);
	int16_t read16(uint32_t addr);
	int32_t read32(uint32_t addr);

	//vmemory(size_t size);
	vmemory() {}

private:
	std::unordered_map <uint32_t, char*> pages;
	char* getpage(uint32_t addr);
};

struct page
{
	bool active;
	char* buf;
};

class vmemory_pt : public mem_if
{
public:
	void write32(uint32_t addr, int32_t data);
	void write16(uint32_t addr, int16_t data);
	void write8(uint32_t addr, int8_t data);

	int8_t read8(uint32_t addr);
	int16_t read16(uint32_t addr);
	int32_t read32(uint32_t addr);

	//vmemory(size_t size);
	vmemory_pt();

private:
	page pages[PAGEMASK / (~PAGEMASK + 1) + 1] = {};
	char* getpage(uint32_t addr);
};

#endif //_VMEMORY_H
