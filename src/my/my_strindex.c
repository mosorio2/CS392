#include "../../include/my.h"

char* my_strindex(char* p, char c)
{
	int i = 0;
	char *done;
	if(p == NULL)
	{
		return NULL;
	}
	if(c == '\0')
	{
		return NULL;
	}
	done = NULL;
	if(p != NULL)
	{
		while(p[i] != '\0')
		{
			if(p[i] == c)
			{
				done = &p[i];
				return done;
			}
			i++;
		}
	}
	return NULL;
}