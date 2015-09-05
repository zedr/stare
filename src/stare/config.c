#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "types.h"

char *join_str(char *str1, char *str2)
{
	char *dest;
	asprintf(&dest, "%s %s", str1, str2);
	return dest;
}

void set_defaults(struct config *conf)
{
	conf->verbose = 0;
	conf->what = "";
	conf->cmd = "";
}

struct config *get_config(int argc, char *argv[])
{
	int i;
	char *opt = "";
	struct config *conf = (struct config *) malloc(sizeof *conf);
	bool is_command = 0;

	if (argc > 0 && conf != NULL) {
		set_defaults(conf);

		for (i=1; i < argc; i++) {
			opt = argv[i];

			if (is_command) {
				conf->cmd = opt;
				is_command = 0;
			} else if (strcmp("-v", opt) == 0) {
				conf->verbose = 1;
			} else if (strcmp("-c", opt) == 0) {
				is_command = 1;
				continue;
			} else if (opt[0] == '-') {
			} else {
				conf->what = opt;
			}
		}
	}

	return conf;
}

bool is_valid_config(struct config *conf)
{
	bool verbose = conf->verbose;

	if (access(conf->what, F_OK) != -1)
		return 1;
	else if (verbose)
		printf("File to watch wasn't found: %s\n", conf->what);

	return 0;
}

void print_config(struct config *conf)
{
	if (conf->verbose)
		puts("High verbosity.");
	else
		puts("Low verbosity.");
	printf("Watching: %s\n", conf->what);
	printf("Will execute: %s\n", conf->cmd);
}


