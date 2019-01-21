#include "opcodes.h"

static const opcodes_t opcodes_g[NB_OPCODES] =
{
	{ 0xFFFF, 0x00E0, &opcode_00E0 },
	{ 0xFFFF, 0x00EE, &opcode_00EE },
	{ 0xF000, 0x1000, &opcode_1NNN },
	{ 0xF000, 0x2000, &opcode_2NNN },
	{ 0xF000, 0x3000, &opcode_3XNN },
	{ 0xF000, 0x4000, &opcode_4XNN },
	{ 0xF000, 0x5000, &opcode_5XY0 },
	{ 0xF000, 0x6000, &opcode_6XNN },
	{ 0xF000, 0x7000, &opcode_7XNN },
	{ 0xF00F, 0x8000, &opcode_8XY0 },
	{ 0xF00F, 0x8001, &opcode_8XY1 },
	{ 0xF00F, 0x8002, &opcode_8XY2 },
	{ 0xF00F, 0x8003, &opcode_8XY3 },
	{ 0xF00F, 0x8004, &opcode_8XY4 },
	{ 0xF00F, 0x8005, &opcode_8XY5 },
	{ 0xF00F, 0x8006, &opcode_8XY6 },
	{ 0xF00F, 0x8007, &opcode_8XY7 },
	{ 0xF00F, 0x800E, &opcode_8XYE },
	{ 0xF000, 0x9000, &opcode_9XY0 },
	{ 0xF000, 0xA000, &opcode_ANNN },
	{ 0xF000, 0xB000, &opcode_BNNN },
	{ 0xF000, 0xC000, &opcode_CXNN },
	{ 0xF000, 0xD000, &opcode_DXYN },
	{ 0xF0FF, 0xE09E, &opcode_EX9E },
	{ 0xF0FF, 0xE0A1, &opcode_EXA1 },
	{ 0xF0FF, 0xF007, &opcode_FX07 },
	{ 0xF0FF, 0xF00A, &opcode_FX0A },
	{ 0xF0FF, 0xF015, &opcode_FX15 },
	{ 0xF0FF, 0xF018, &opcode_FX18 },
	{ 0xF0FF, 0xF01E, &opcode_FX1E },
	{ 0xF0FF, 0xF029, &opcode_FX29 },
	{ 0xF0FF, 0xF033, &opcode_FX33 },
	{ 0xF0FF, 0xF055, &opcode_FX55 },
	{ 0xF0FF, 0xF065, &opcode_FX65 }
};

bool handle_opcodes(cpu_t *cpu, window_t *window)
{
	for (uint8_t i = 0; i < NB_OPCODES ; ++i) {
		if ((cpu->opcode & opcodes_g[i].mask) == opcodes_g[i].code)
			opcodes_g[i].opcode(cpu, window);
	}
	return true;
}
