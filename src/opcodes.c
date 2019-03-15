#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "opcodes.h"

// Clears the screen.
void opcode_00E0(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 00E0 && pc = %d\n", cpu->pc);
	framebuffer_clear(&window->framebuffer);
	cpu->pc += 2;
}

// Returns from a subroutine.
void opcode_00EE(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 00EE && pc = %d\n", cpu->pc);
	cpu->sp--;
	cpu->pc = cpu->stack[cpu->sp];
	(void)window;
}

// Jumps to address NNN.
void opcode_1NNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 1NNN && pc = %d\n", cpu->pc);
	cpu->pc = cpu->opcode & 0x0FFF;
	(void)window;
}

// Calls subroutine at NNN.
void opcode_2NNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 2NNN && pc = %d\n", cpu->pc);
	cpu->stack[cpu->sp] = cpu->pc;
	cpu->sp++;
	cpu->pc = cpu->opcode & 0x0FFF;
	(void)window;
}

// Skips the next instruction if VX equals NN.
void opcode_3XNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 3XNN && pc = %d\n", cpu->pc);
	if (cpu->V[(cpu->opcode & 0x0F00) >> 8] == (cpu->opcode & 0x00FF))
		cpu->pc += 2;
	cpu->pc += 2;
	(void)window;
}

// Skips the next instruction if VX doesn't equal NN.
void opcode_4XNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 4XNN && pc = %d\n", cpu->pc);
	if (cpu->V[(cpu->opcode & 0x0F00) >> 8] != (cpu->opcode & 0x00FF))
		cpu->pc += 2;
	cpu->pc += 2;
	(void)window;
}

// Skips the next instruction if VX equals VY.
void opcode_5XY0(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 5XY0 && pc = %d\n", cpu->pc);
	if (cpu->V[(cpu->opcode & 0x0F00) >> 8] == cpu->V[(cpu->opcode & 0x00F0) >> 4])
		cpu->pc += 2;
	cpu->pc += 2;
	(void)window;
}

// Sets VX to NN.
void opcode_6XNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 6XNN && pc = %d\n", cpu->pc);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] = (cpu->opcode & 0x00FF);
	cpu->pc += 2;
	(void)window;
}

// Adds NN to VX.
void opcode_7XNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 7XNN && pc = %d\n", cpu->pc);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] += (cpu->opcode & 0x00FF);
	cpu->pc += 2;
	(void)window;
}

// Sets VX to the value of VY.
void opcode_8XY0(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY0 && pc = %d\n", cpu->pc);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] = cpu->V[(cpu->opcode & 0x00F0) >> 4];
	cpu->pc += 2;
	(void)window;
}

// Sets VX to VX or VY.
void opcode_8XY1(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY1 && pc = %d\n", cpu->pc);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] |= cpu->V[(cpu->opcode & 0x00F0) >> 4];
	cpu->pc += 2;
	(void)window;
}

// Sets VX to VX and VY.
void opcode_8XY2(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY2 && pc = %d\n", cpu->pc);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] &= cpu->V[(cpu->opcode & 0x00F0) >> 4];
	cpu->pc += 2;
	(void)window;
}

// Sets VX to VX xor VY.
void opcode_8XY3(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY3 && pc = %d\n", cpu->pc);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] ^= cpu->V[(cpu->opcode & 0x00F0) >> 4];
	cpu->pc += 2;
	(void)window;
}

// Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there isn't.
void opcode_8XY4(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY4 && pc = %d\n", cpu->pc);
	if (cpu->V[(cpu->opcode & 0x00F0) >> 4] > (0xFF - cpu->V[(cpu->opcode & 0x0F00) >> 8]))
		cpu->V[0xF] = 1;
	else
		cpu->V[0xF] = 0;
	cpu->V[(cpu->opcode & 0x0F00) >> 8] += cpu->V[(cpu->opcode & 0x00F0) >> 4];
	cpu->pc += 2;
	(void)window;
}

// VY is subtracted from VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
void opcode_8XY5(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY5 && pc = %d\n", cpu->pc);
	if (cpu->V[(cpu->opcode & 0x0F00) >> 8] > cpu->V[(cpu->opcode & 0x00F0) >> 4])
		cpu->V[0xF] = 1;
	else
		cpu->V[0xF] = 0;
	cpu->V[(cpu->opcode & 0x0F00) >> 8] -= cpu->V[(cpu->opcode & 0x00F0) >> 4];
	cpu->pc += 2;
	(void)window;
}

// Stores the least significant bit of VX in VF and then shifts VX to the right by 1.
void opcode_8XY6(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY6 && pc = %d\n", cpu->pc);
	cpu->V[0xF] = (cpu->V[(cpu->opcode & 0x0F00) >> 8] & 1);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] >>= 1;
	cpu->pc += 2;
	(void)window;
}

// Sets VX to VY minus VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
void opcode_8XY7(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XY7 && pc = %d\n", cpu->pc);
	if (cpu->V[(cpu->opcode & 0x00F0) >> 4] > cpu->V[(cpu->opcode & 0x0F00) >> 8])
		cpu->V[0xF] = 1;
	else
		cpu->V[0xF] = 0;
	cpu->V[(cpu->opcode & 0x0F00) >> 8] = cpu->V[(cpu->opcode & 0x00F0) >> 4] - cpu->V[(cpu->opcode & 0x0F00) >> 8];
	cpu->pc += 2;
	(void)window;
}

// Stores the most significant bit of VX in VF and then shifts VX to the left by 1.
void opcode_8XYE(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 8XYE && pc = %d\n", cpu->pc);
	cpu->V[0xF] = cpu->V[(cpu->opcode & 0x0F00) >> 8] & (1 << 7);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] <<= 1;
	cpu->pc += 2;
	(void)window;
}

// Skips the next instruction if VX doesn't equal VY.
void opcode_9XY0(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = 9XY0 && pc = %d\n", cpu->pc);
	if (cpu->V[(cpu->opcode & 0x0F00) >> 8] != cpu->V[(cpu->opcode & 0x00F0) >> 4])
		cpu->pc += 2;
	cpu->pc += 2;
	(void)window;
}

// Sets I to the address NNN.
void opcode_ANNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = ANNN && pc = %d\n", cpu->pc);
	cpu->I = cpu->opcode & 0x0FFF;
	cpu->pc += 2;
	(void)window;
}

// Jumps to the address NNN plus V0.
void opcode_BNNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = BNNN && pc = %d\n", cpu->pc);
	cpu->pc = (cpu->opcode & 0x0FFF) + cpu->V[0];
	(void)window;
}

// Sets VX to the result of a bitwise and operation on a random number (Typically: 0 to 255) and NN.
void opcode_CXNN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = CXNN && pc = %d\n", cpu->pc);
	srand(time(NULL));
	cpu->V[(cpu->opcode & 0x0F00) >> 8] = (rand() % 0xFF) & (cpu->opcode & 0x00FF);
	cpu->pc += 2;
	(void)window;
}

// Draws a sprite at coordinate (VX, VY) that has a width of 8 pixels and a height of N pixels.
void opcode_DXYN(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = DXYN && pc = %d\n", cpu->pc);
	uint8_t x = cpu->V[(cpu->opcode & 0x0F00) >> 8];
	uint8_t y = cpu->V[(cpu->opcode & 0x00F0) >> 4];
	uint16_t height = cpu->opcode & 0x000F;
	uint8_t pixel;

	cpu->V[0xF] = 0;
	for (uint16_t i = 0; i < height; ++i) {
		pixel = cpu->memory[cpu->I + i];
		for (uint16_t j = 0; j < 8; ++j) {
			if ((pixel & (0x80 >> j)) != 0) {
				if (pixel_is_set(&window->framebuffer, x + j, y + i) == true) {
					cpu->V[0xF] = 1;
					put_pixel(&window->framebuffer, x + j, y + i, sfBlack);
				} else
					put_pixel(&window->framebuffer, x + j, y + i, sfWhite);
			}
		}
	}
	cpu->pc += 2;
}

// Skips the next instruction if the key stored in VX is pressed.
void opcode_EX9E(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = EX9E && pc = %d\n", cpu->pc);
	if (cpu->keys[cpu->V[(cpu->opcode & 0x0F00) >> 8]] == true)
		cpu->pc += 2;
	cpu->pc += 2;
	(void)window;
}

// Skips the next instruction if the key stored in VX isn't pressed.
void opcode_EXA1(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = EXA1 && pc = %d\n", cpu->pc);
	if (cpu->keys[cpu->V[(cpu->opcode & 0x0F00) >> 8]] == false)
		cpu->pc += 2;
	cpu->pc += 2;
	(void)cpu;
	(void)window;
}

// Sets VX to the value of the delay timer.
void opcode_FX07(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX07 && pc = %d\n", cpu->pc);
	cpu->V[(cpu->opcode & 0x0F00) >> 8] = cpu->delay_timer;
	cpu->pc += 2;
	(void)window;
}

// A key press is awaited, and then stored in VX.
void opcode_FX0A(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX0A && pc = %d\n", cpu->pc);
	for (uint8_t i = 0; i < NB_KEYS ; ++i) {
		if (cpu->keys[i] == true) {
			cpu->pc += 2;
			return;
		}
	}
	(void)window;
}

// Sets the delay timer to VX.
void opcode_FX15(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX15 && pc = %d\n", cpu->pc);
	cpu->delay_timer = cpu->V[(cpu->opcode & 0x0F00) >> 8];
	cpu->pc += 2;
	(void)window;
}

// Sets the sound timer to VX.
void opcode_FX18(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX18 && pc = %d\n", cpu->pc);
	cpu->sound_timer = cpu->V[(cpu->opcode & 0x0F00) >> 8];
	cpu->pc += 2;
	(void)window;
}

// Adds VX to I.
void opcode_FX1E(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX1E && pc = %d\n", cpu->pc);
	cpu->I += cpu->V[(cpu->opcode & 0x0F00) >> 8];
	cpu->pc += 2;
	(void)window;
}

// Sets I to the location of the sprite for the character in VX.
void opcode_FX29(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX29 && pc = %d\n", cpu->pc);
	cpu->I = cpu->V[(cpu->opcode & 0x0F00) >> 8] * 5;
	cpu->pc += 2;
	(void)window;
}

// Stores the binary-coded decimal representation of VX
void opcode_FX33(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX33 && pc = %d\n", cpu->pc);
	cpu->memory[cpu->I] = cpu->V[(cpu->opcode & 0x0F00) >> 8] / 100;
	cpu->memory[cpu->I + 1] = (cpu->V[(cpu->opcode & 0x0F00) >> 8] % 10) % 10;
	cpu->memory[cpu->I + 2] = (cpu->V[(cpu->opcode & 0x0F00) >> 8] % 100) % 10;
	cpu->pc += 2;
	(void)window;
}

// Stores V0 to VX (including VX) in memory starting at address I.
void opcode_FX55(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX55 && pc = %d\n", cpu->pc);
	for (uint8_t i = 0; i <= (cpu->opcode & 0x0F00) >> 8 ; ++i) {
		cpu->memory[cpu->I + i] = cpu->V[i];
	}
	cpu->pc += 2;
	(void)window;
}

// Fills V0 to VX (including VX) with values from memory starting at address I.
void opcode_FX65(cpu_t *cpu, window_t *window)
{
	printf("DEBUG: OPCODE = FX65 && pc = %d\n", cpu->pc);
	for (uint8_t i = 0; i <= (cpu->opcode & 0x0F00) >> 8 ; ++i) {
		cpu->V[i] = cpu->memory[cpu->I + i];
	}
	cpu->pc += 2;
	(void)window;
}
