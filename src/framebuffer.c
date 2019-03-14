#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "window.h"

static const uint8_t WIDTH = 64;
static const uint8_t HEIGHT = 32;
static const char *ERR_FRAME = "Error when allocating framebuffer";

bool framebuffer_initialize(framebuffer_t *framebuffer)
{
	memset(framebuffer, 0, sizeof(framebuffer_t));
	framebuffer->width = WIDTH;
	framebuffer->height = HEIGHT;
	framebuffer->pixels = calloc(WIDTH * HEIGHT * 4, sizeof(sfUint8));
	if (!framebuffer->pixels) {
		printf("%s\n", ERR_FRAME);
		return false;
	}
	return true;
}

void framebuffer_free(framebuffer_t *framebuffer)
{
	free(framebuffer->pixels);
	free(framebuffer);
}

void framebuffer_clear(framebuffer_t *framebuffer)
{
	for (uint16_t i = 0; i < WIDTH * HEIGHT * 4 ; ++i) {
		framebuffer->pixels[i] = 0;
	}
}

bool pixel_is_set(framebuffer_t *framebuffer, uint8_t x, uint8_t y)
{
	if (framebuffer->pixels[(framebuffer->width * y + x) * 4] == sfWhite.r
		&& framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] == sfWhite.g
		&& framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] == sfWhite.b
		&& framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] == sfWhite.a)
		return true;
	return false;
}

void put_pixel(framebuffer_t *framebuffer, uint8_t x, uint8_t y, sfColor color)
{
	if (x <= framebuffer->width && y <= framebuffer->height) {
		framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
		framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
		framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
		framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
	}
}
