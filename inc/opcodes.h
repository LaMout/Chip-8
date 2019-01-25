#pragma once

#include "chip8.h"
#include "window.h"

// 35 with useless 0x0NNN
#define NB_OPCODES (34)

typedef void (*opcode_t)(cpu_t *, window_t *);

typedef struct opcodes_s
{
	const uint16_t mask;
	const uint16_t code;
	opcode_t opcode;
} opcodes_t;

/*
 * Handle Opcodes
 */
bool handle_opcodes(cpu_t *cpu, window_t *window);

/*
 * Opcodes
 */
void opcode_00E0(cpu_t *, window_t *);
void opcode_00EE(cpu_t *, window_t *);
void opcode_1NNN(cpu_t *, window_t *);
void opcode_2NNN(cpu_t *, window_t *);
void opcode_3XNN(cpu_t *, window_t *);
void opcode_4XNN(cpu_t *, window_t *);
void opcode_5XY0(cpu_t *, window_t *);
void opcode_6XNN(cpu_t *, window_t *);
void opcode_7XNN(cpu_t *, window_t *);
void opcode_8XY0(cpu_t *, window_t *);
void opcode_8XY1(cpu_t *, window_t *);
void opcode_8XY2(cpu_t *, window_t *);
void opcode_8XY3(cpu_t *, window_t *);
void opcode_8XY4(cpu_t *, window_t *);
void opcode_8XY5(cpu_t *, window_t *);
void opcode_8XY6(cpu_t *, window_t *);
void opcode_8XY7(cpu_t *, window_t *);
void opcode_8XYE(cpu_t *, window_t *);
void opcode_9XY0(cpu_t *, window_t *);
void opcode_ANNN(cpu_t *, window_t *);
void opcode_BNNN(cpu_t *, window_t *);
void opcode_CXNN(cpu_t *, window_t *);
void opcode_DXYN(cpu_t *, window_t *);
void opcode_EX9E(cpu_t *, window_t *);
void opcode_EXA1(cpu_t *, window_t *);
void opcode_FX07(cpu_t *, window_t *);
void opcode_FX0A(cpu_t *, window_t *);
void opcode_FX15(cpu_t *, window_t *);
void opcode_FX18(cpu_t *, window_t *);
void opcode_FX1E(cpu_t *, window_t *);
void opcode_FX29(cpu_t *, window_t *);
void opcode_FX33(cpu_t *, window_t *);
void opcode_FX55(cpu_t *, window_t *);
void opcode_FX65(cpu_t *, window_t *);
