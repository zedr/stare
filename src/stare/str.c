#include <stdlib.h>
#include "str.h"

struct str_arr *create_str_arr(char *first)
{
	struct str_arr *ptr = (struct str_arr *) malloc(sizeof(*ptr));
	if (first != NULL) {
		ptr->strs = malloc(sizeof(ptr->strs));
		ptr->strs[0] = first;
		ptr->len = 1;
	} else {
		ptr->len = 0;
	}
	return ptr;
}
