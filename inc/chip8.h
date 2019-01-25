#pragma once

#include <stdint.h>
#include <stdbool.h>

#define MEM_SIZE	(4096)
#define REG_SIZE	(16)
#define STACK_SIZE	(16)
#define PROG_START	(512)

typedef struct cpu_s
{
	uint16_t opcode;
	uint8_t memory[MEM_SIZE];
	uint8_t V[REG_SIZE];
	uint16_t I;
	uint16_t pc;
	uint8_t delay_timer;
	uint8_t sound_timer;
	uint16_t stack[STACK_SIZE];
	uint8_t sp;
} cpu_t;

bool cpu_initialize(cpu_t *cpu, const char *filename);

int chip8(const char *filename);

void memory_dump(cpu_t *cpu);
