#include "../../include/my.h"


char* my_strcpy(char* dst, char* src) {
	int i = 0;
	
	if (dst == NULL || src == NULL)
		return NULL;

	while (src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}
