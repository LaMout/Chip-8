#pragma once

#include "chip8.h"
#include "window.h"

typedef struct keys_s
{
	sfKeyCode keyCode;
	uint8_t pos;
} keys_t;

/*
 * Handle Keys
 */
bool handle_keys(cpu_t *cpu, const sfKeyCode *keyCode, bool value);
