#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "minunit.h"
#include "../stare/types.h"
#include "../stare/config.h"

MU_TEST(test_can_parse_verbose_arg)
{
	int argc = 3;
	const char *argv[] = {"stare", "-v"};
	struct config *conf = get_config(argc, argv);
	bool verbose = conf->verbose;

	mu_assert(verbose, "verbose is false, it should be true");

	free(conf);
}

MU_TEST(test_config_from_1_argument)
{
	int argc = 2;
	const char *argv[] = {"stare", "world"};
	struct config *conf = get_config(argc, argv);
	char *what = conf->what;

	mu_assert(strcmp(what, "world") == 0, "`what` is not equal to 'world'");

	free(conf);
}

MU_TEST(test_config_using_command_option)
{
	int argc = 4;
	const char *argv[] = {"stare", "-c", "foo", "world"};
	struct config *conf = get_config(argc, argv);
	char *cmd = conf->cmd;
	char *what = conf->what;

	mu_assert(strcmp(cmd, "foo") == 0, "`cmd` is not equal to 'foo'");
	mu_assert(strcmp(what, "world") == 0, "`what` is not equal to 'world'");

	free(conf);
}

MU_TEST_SUITE(all_tests)
{
	MU_RUN_TEST(test_can_parse_verbose_arg);
	MU_RUN_TEST(test_config_from_1_argument);
	MU_RUN_TEST(test_config_using_command_option);
}

int main(int argc, const char *argv[])
{
	MU_RUN_TEST(all_tests);
	MU_REPORT();

	return 0;
}
