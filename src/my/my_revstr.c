#include "../../include/my.h"

int my_revstr(char* s)
{
	int temp;
	int rep;
	int i;
	int j;
	if (s == NULL)
	{
		return -1;
	}
	i =0;
	j = (my_strlen(s) - 1);
	while(i < j)
	{
		temp = s[i];
		rep = s[j];
		s[i] = rep;
		s[j] = temp;
		i++;
		j--;
	}	
	return my_strlen(s);
}