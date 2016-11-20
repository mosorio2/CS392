#include "../../include/my.h"

int my_pow(int num, int exp)
{
	int temp = num;

	if (exp == 0)
	{
		return 1;
	}
	if (exp == 1)
	{
		return num;
	}
	while(exp > 1)
	{
		temp = temp * num;
		exp--;
	}
	return temp;
}

void my_int(int i)
{
	int j;
	int temp;
	char base;
	if (i < 0)
	{
		i = i * -1;
		my_char('-');
	}
	temp = i;
	j = 0;
	if(i == 0)
	{
		my_char('0');
	}
	
	while(temp > 0)
	{
		temp=temp/10;
		j++;
	}
	while(j > 0)
	{
		base = i/(my_pow(10, j - 1)) + '0';
		my_char(base);
		i=i%(my_pow(10, j - 1));
		j--;
	}
}