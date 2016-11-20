#include "../../include/my.h"


int my_strfind(char* src, char c) {
	int i = 0;
	
	if (src == NULL)
		return -1;
	if (src[0] == '\0')
		return -1;
	if (c == '\0')
		return -1;

	while (src[i] != '\0') {
		if (c == src[i]) {
			return i;
		}
		i++;
	}
	return -1;
}
