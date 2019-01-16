#include <stdio.h>
#include <unistd.h>
#include "chip8.h"

void memory_dump(cpu_t *cpu)
{
	for (uint16_t i = 0; i < MEM_SIZE; ++i) {
		printf("%02x ", cpu->memory[i]);
		if (i % 32 == 0 && i > 0)
			printf("\n");
	}
}
