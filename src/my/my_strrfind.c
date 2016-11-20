#include "../../include/my.h"

int my_strrfind(char* src, char c) {
	int i = 0;
	int index = -1;
	
	if (src == NULL)
		return -1;
	if (src[0] == '\0')
		return -1;
	if (c == '\0')
		return -1;
	
	while (src[i] != '\0') {
		if (c == src[i]) {
			index = i;
		}
		i++;
	}
	return index;
}
