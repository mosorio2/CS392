#include "../../include/my.h"

int my_strncmp(char* a, char* b, int n) {
	int i = 0;
	if (a == NULL && b == NULL)
		return 0;
	if (a == NULL)
		return -1;
	if (b == NULL)
		return 1;

	if (n < 0 || n == 0)
		return 0;

	while(n > 0) {
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		if (a[i] == '\0' && b[i] == '\0')
			return 0;
		i++;
		n--;
	}
	return 0;
}
