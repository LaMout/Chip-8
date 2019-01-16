#include <stdlib.h>
#include "chip8.h"
#include "opcodes.h"

int chip8(const char *filename)
{
	cpu_t cpu;

	if (cpu_initialize(&cpu, filename) == false)
		return EXIT_FAILURE;
	memory_dump(&cpu);
	return EXIT_SUCCESS;
}
