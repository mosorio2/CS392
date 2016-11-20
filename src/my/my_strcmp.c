#include "../../include/my.h"


int my_strcmp(char* a, char* b) {
	int i = 0;

	if (a == NULL && b == NULL)
		return 0;
	if (a == NULL)
		return -1;
	if (b == NULL)
		return 1;
	
	while(a[i] != '\0' || b[i] != '\0') {
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		i++;
	}
	return 0;
}
