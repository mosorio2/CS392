#include "../../include/my.h"

char* my_strcat(char* dst, char* src) {
	int len = my_strlen(dst);
	int i = 0;
	
	if (dst == NULL || src == NULL)
		return NULL;

	while (src[i] != '\0') {
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';

	return dst;
}
