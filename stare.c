#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stare.h"


void usage(void)
{
	puts("Usage: stare <what> <command [arg1] [arg2] .. [argN]>");
}

struct config *get_config(int argc, char *argv[])
{
	struct config *conf = (struct config *) malloc(sizeof *conf);
	char *substr = "";
	int i = 1;

	conf->verbose = 0;
	conf->what = "";
	conf->command = "";

	do {
		substr = argv[i];

		if (strcmp(substr, "-v") == 0) {
			conf->verbose = 1;
		} else {
			if (strcmp(conf->what, "") == 0) {
				conf->what = substr;
			} else {
				conf->command = substr;
			}
		}

	} while(++i < argc);

	return conf;
}

int main(int argc, char *argv[])
{
	struct config *conf;

	if (argc > 2) {
		conf = get_config(argc, argv);
		if (conf->verbose) {
			puts("High verbosity.");
			printf("Watching: %s\n", conf->what);
			printf("Will execute: %s\n", conf->command);
		}
		free(conf);
	} else {
		usage();
	}
	return 0;
}
