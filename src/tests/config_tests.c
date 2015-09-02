#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "../stare/types.h"
#include "../stare/config.h"

int tests_run = 0;

static char * test_can_parse_verbose_arg()
{
	int argc = 3;
	char *argv[] = {"stare", "-v"};
	struct config *conf = get_config(argc, argv);
	bool verbose = conf->verbose;

	mu_assert("verbose is false, it should be true", verbose);
	return 0;
}

static char * test_config_from_arguments()
{
	int argc = 3;
	char *argv[] = {"stare", "world"};
	struct config *conf = get_config(argc, argv);
	char *what = conf->what;

	mu_assert("what is not equal to 'world' ", strcmp(what, "world") == 0);
	return 0;
}

static char * all_tests()
{
	mu_run_test(test_can_parse_verbose_arg);
	mu_run_test(test_config_from_arguments);
	return 0;
}

int main(int argc, const char *argv[])
{
	char *result = all_tests();
	if (result ==0) {
		puts("OK");
	} else {
		printf("KO: %s\n", result);
	}

	return 0;
}
