#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>
#include <sys/inotify.h>
#include "constants.h"
#include "types.h"
#include "config.h"

void usage(void)
{
	puts("Usage: stare PATH_1 [PATH_2, ...PATH_N] [-c \"COMMAND\"]");
}

void inotify_watch(char *what, char *command)
{
	int fd, wd, length;
	char buffer[BUF_LEN];
	int IN_FLAGS = IN_CREATE | IN_MODIFY | IN_DELETE;

	fd = inotify_init();
	if (fd < 0)
		puts("Inotify init error.");
	else {
		wd = inotify_add_watch(fd, what, IN_FLAGS);
		length = read(fd, buffer, BUF_LEN);
		if (length < 0)
			puts("Inotify read error.");
		else {
			system(command);
		}
	}
	inotify_rm_watch(fd, wd);
	close(fd);
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
			while(1)
				inotify_watch(conf->what, conf->cmd);
			exit_code = 0;
		}

		free(conf);
		conf = NULL;
	} else {
		usage();
		exit_code = EX_USAGE;
	}

	return exit_code;
}
