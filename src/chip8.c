#include <stdlib.h>
#include "chip8.h"
#include "window.h"

int chip8(const char *filename)
{
	cpu_t cpu;
	window_t window;

	if (cpu_initialize(&cpu, filename) == false)
		return EXIT_FAILURE;
//	memory_dump(&cpu);
	if (window_initialize(&window) == false)
		return EXIT_FAILURE;
//	 while (sfRenderWindow_isOpen(window.window)) {
//		sfRenderWindow_clear(window.window, sfBlack);
//		sfRenderWindow_display(window.window);
//	}
	return EXIT_SUCCESS;
}
