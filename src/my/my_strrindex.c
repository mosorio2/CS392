#include "../../include/my.h"

char* my_strrindex(char* p, char c)
{
	int i;
	char *done;
	if(p == NULL)
	{
		return NULL;
	}
	if(c == '\0')
	{
		return NULL;
	}
	i = my_strlen(p) - 1;
	done = NULL;
	if (i < 0)
		return "";
		
	if(p != NULL)
	{
		while(p[i] != c)
		{
			i--;
			if(i < 0)
				return "";
		}
		done = &p[i];
		return done;
	}
	return NULL;
}