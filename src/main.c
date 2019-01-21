#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chip8.h"

static const char *USAGE = "USAGE\n\t%s ROM_NAME\n";

static void dump_help(const char *name)
{
	printf(USAGE, name);
}

int main(int ac, char **av)
{
	if (ac < 2 || !strcmp(av[1], "-h")) {
		dump_help(av[0]);
		return EXIT_SUCCESS;
	}
	return chip8(av[1]);
}
