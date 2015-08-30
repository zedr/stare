#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>
#include "stare.h"

void usage(void)
{
	puts("Usage: stare <what> <command [arg1] [arg2] .. [argN]>");
}

char *join_str(char *str1, char *str2)
{
	char *dest;
	asprintf(&dest, "%s %s", str1, str2);
	return dest;
}

struct config *get_config(int argc, char *argv[])
{
	int i = 1;
	char *str = "";
	struct config *conf = (struct config *) malloc(sizeof *conf);

	if (conf != NULL) {
		conf->verbose = 0;
		conf->what = "";
		conf->cmd = "";

		do {
			str = argv[i];
			if (strcmp(str, "-v") == 0) {
				conf->verbose = 1;
			} else {
				if (strcmp(conf->what, "") == 0) {
					conf->what = str;
				} else if (strcmp(conf->cmd, "") == 0) {
					conf->cmd = str;
				} else {
					conf->cmd = join_str(conf->cmd, str);
				}
			}
		} while(++i < argc);
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

int main(int argc, char *argv[])
{
	struct config *conf;
	int exit_code = 1;

	if (argc > 2) {
		conf = get_config(argc, argv);

		if (conf == NULL) {
			puts("Out of memory.");
			return 1;
		}

		if (conf->verbose)
			print_config(conf);

		if (is_valid_config(conf)) {
			puts("Valid.");
			exit_code = 0;
		}

		free(conf);
	} else {
		usage();
		exit_code = EX_USAGE;
	}

	return exit_code;
}
