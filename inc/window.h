#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct framebuffer_s
{
	sfUint8 *pixels;
	uint8_t width;
	uint8_t height;
} framebuffer_t;

typedef struct window_s
{
	sfVideoMode mode;
	sfRenderWindow *window;
	sfTexture *texture;
	sfSprite *sprite;
	framebuffer_t framebuffer;
} window_t;

bool framebuffer_initialize(framebuffer_t *framebuffer);
void framebuffer_free(framebuffer_t *framebuffer);
void framebuffer_clear(framebuffer_t *framebuffer);
bool pixel_is_set(framebuffer_t *framebuffer, uint8_t x, uint8_t y);
void put_pixel(framebuffer_t *framebuffer, uint8_t x, uint8_t y, sfColor color);
bool window_initialize(window_t *window);
