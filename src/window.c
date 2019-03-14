#include <memory.h>
#include <stdio.h>
#include "window.h"

static const uint16_t WIDTH = 64;
static const uint16_t HEIGHT = 32;
static const char *ERR_WIN = "Something went wrong when creating the window";

bool window_initialize(window_t *window)
{
	memset(window, 0, sizeof(window_t));
	window->mode.width = WIDTH;
	window->mode.height = HEIGHT;
	window->mode.bitsPerPixel = 32;
	window->window = sfRenderWindow_create(window->mode, "Chip8", sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window->window, 60);
	window->texture = sfTexture_create(WIDTH, HEIGHT);
	window->sprite = sfSprite_create();
	if (framebuffer_initialize(&window->framebuffer) == false
		|| !window->window || !window->texture || !window->sprite) {
		printf("%s\n", ERR_WIN);
		return false;
	}
	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
	return true;
}
