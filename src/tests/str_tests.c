#include <string.h>
#include <stdlib.h>
#include "minunit.h"
#include "../stare/str.h"

MU_TEST(test_create_arr_of_str_from_scratch)
{
	struct str_arr *ptr = create_str_arr("test");
	char *str = (ptr->strs)[0];

	mu_assert(ptr->len == 1, "length of sequence is not 0");
	mu_assert(strcmp("test", str) == 0, "first element is not equal to 1");

	free(ptr);
}

MU_TEST_SUITE(str_tests)
{
	MU_RUN_TEST(test_create_arr_of_str_from_scratch);
}

int main(int argc, const char *argv[])
{
	MU_RUN_TEST(str_tests);
	MU_REPORT();
	return 0;
}
