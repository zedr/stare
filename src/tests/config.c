#include <stdio.h>
#include "minunit.h"

int tests_run = 0;

static char * test_foo() {
	mu_assert("2 + 2 != 4", (2 + 2) == 5);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_foo);
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
