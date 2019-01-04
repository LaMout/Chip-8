#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void dump_help(const char *name)
{
	printf("USAGE\n\t%s ROM_NAME\n", name);
}

int main(int ac, char **av)
{
	if (ac < 2 || !strcmp(av[1], "-h")) {
		dump_help(av[0]);
		return EXIT_SUCCESS;
	}
	return EXIT_SUCCESS;
}