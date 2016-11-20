#include "../../include/my.h"

void my_num_base(int i, char* s)
{
	int length;
	if(s == '\0')
	{
		my_str("error: char* is NULL");
		return;
	}
	if (i == 0)
	{
		return;
	}
	if (s == NULL)
	{
		return;
	}
	if(i < 0)
	{
		i = i* -1;
		my_char('-');
	}
	length = my_strlen(s);
	if(length < 1)
		return;
	
	if (length == 1)
	{
		while (length < i + 1)
		{
			my_str(s);
			length++;
		}
		return;
	}
	if (i != 0)
	{
		my_num_base(i / length, s);
		my_char(s[i % length]);
	}
}