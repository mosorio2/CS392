#include "../../include/my.h"

int my_strlen(char* s)
{
	int i = 0;
	if (s == NULL)
	{
		return -1;
	}
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}