#include "opcodes.h"

// Clears the screen.
void opcode_00E0(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Returns from a subroutine.
void opcode_00EE(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Jumps to address NNN.
void opcode_1NNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Calls subroutine at NNN.
void opcode_2NNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Skips the next instruction if VX equals NN.
void opcode_3XNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Skips the next instruction if VX doesn't equal NN.
void opcode_4XNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Skips the next instruction if VX equals VY.
void opcode_5XY0(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to NN.
void opcode_6XNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Adds NN to VX.
void opcode_7XNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to the value of VY.
void opcode_8XY0(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to VX or VY.
void opcode_8XY1(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to VX and VY.
void opcode_8XY2(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to VX xor VY.
void opcode_8XY3(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there isn't.
void opcode_8XY4(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// VY is subtracted from VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
void opcode_8XY5(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Stores the least significant bit of VX in VF and then shifts VX to the right by 1.
void opcode_8XY6(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to VY minus VX. VF is set to 0 when there's a borrow, and 1 when there isn't.
void opcode_8XY7(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Stores the most significant bit of VX in VF and then shifts VX to the left by 1.
void opcode_8XYE(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Skips the next instruction if VX doesn't equal VY.
void opcode_9XY0(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets I to the address NNN.
void opcode_ANNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Jumps to the address NNN plus V0.
void opcode_BNNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to the result of a bitwise and operation on a random number (Typically: 0 to 255) and NN.
void opcode_CXNN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Draws a sprite at coordinate (VX, VY) that has a width of 8 pixels and a height of N pixels.
void opcode_DXYN(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Skips the next instruction if the key stored in VX is pressed.
void opcode_EX9E(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Skips the next instruction if the key stored in VX isn't pressed.
void opcode_EXA1(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets VX to the value of the delay timer.
void opcode_FX07(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// A key press is awaited, and then stored in VX.
void opcode_FX0A(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets the delay timer to VX.
void opcode_FX15(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets the sound timer to VX.
void opcode_FX18(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Adds VX to I.
void opcode_FX1E(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Sets I to the location of the sprite for the character in VX.
void opcode_FX29(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Stores the binary-coded decimal representation of VX
void opcode_FX33(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Stores V0 to VX (including VX) in memory starting at address I.
void opcode_FX55(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}

// Fills V0 to VX (including VX) with values from memory starting at address I.
void opcode_FX65(cpu_t *cpu, window_t *window)
{
	(void)cpu;
	(void)window;
}
