#include <stdlib.h>
#include <stdio.h>
#include "chip8.h"
#include "window.h"
#include "opcodes.h"
#include "keys.h"

static int emulate_cycle(cpu_t *cpu, window_t *window)
{
	cpu->opcode = cpu->memory[cpu->pc] << 8 | cpu->memory[cpu->pc + 1];
	if (handle_opcodes(cpu, window) == false)
		return EXIT_FAILURE;
	if (cpu->delay_timer > 0)
		cpu->delay_timer--;
	if (cpu->sound_timer > 0) {
		if (cpu->sound_timer == 1)
			printf("Beep\n");
		cpu->sound_timer--;
	}
	return EXIT_SUCCESS;
}

static void handle_events(cpu_t *cpu, window_t *window, sfEvent *event)
{
	while (sfRenderWindow_pollEvent(window->window, event)) {
		if (event->type == sfEvtClosed)
			sfRenderWindow_close(window->window);
		if (event->type == sfEvtKeyPressed)
			handle_keys(cpu, &event->key.code, true);
		if (event->type == sfEvtKeyReleased)
			handle_keys(cpu, &event->key.code, false);
	}
}

static int emulate(cpu_t *cpu, window_t *window)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(window->window)) {
		handle_events(cpu, window, &event);
		emulate_cycle(cpu, window);
		sfTexture_updateFromPixels(window->texture, window->framebuffer.pixels,
			window->framebuffer.width, window->framebuffer.height, 0, 0);
		sfRenderWindow_clear(window->window, sfBlack);
		sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
		sfRenderWindow_display(window->window);
	}
	return EXIT_SUCCESS;
}

int chip8(const char *filename)
{
	cpu_t cpu;
	window_t window;

	if (cpu_initialize(&cpu, filename) == false)
		return EXIT_FAILURE;
	if (window_initialize(&window) == false)
		return EXIT_FAILURE;
	emulate(&cpu, &window);
	return EXIT_SUCCESS;
}
