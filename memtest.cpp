
#include <stdio.h>

#include "memory.h"

int main()
{
	mem_if* mem = new memory(100);
	mem->write8(0, 0x01);
	mem->write8(1, 0x02);
	mem->write8(2, 0x03);
	mem->write8(3, 0x04);

	printf("%08X", mem->read32(0));
	return 0;
}