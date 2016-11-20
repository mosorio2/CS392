#include "../../include/my.h"

char* my_strdup(char* str) {
	int len = my_strlen(str);
	char* dst = (char*) malloc (len * sizeof(char) + 1);
	char* copy = my_strcpy(dst, str);

	if (str == NULL)
		return NULL;

	if (len == 0)
		return NULL;

	return copy;
}
