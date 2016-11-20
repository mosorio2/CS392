#include "../../include/my.h"

char* my_strncpy(char* dst, char* src, int n) {
	int i = 0;
	
	if (dst == NULL || src == NULL)
		return NULL;

	if (n < 0 || n == 0) {
		dst[0] = '\0';
		return dst;
	}

	while (n > 0) {
		if (src[i] == '\0') {
			dst[i] = '\0';
			return dst;
		}
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = '\0';
	return dst;
}
