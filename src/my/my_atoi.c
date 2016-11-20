#include "../../include/my.h"


int atoi_power(int base, int pow) {
	int temp;
	if (pow == 0)
		return 1;
	if (pow == 1)
		return base;

	temp = base;
	while (pow > 1) {
		temp *= base;
		pow--;
	}
	return temp;
}

int my_atoi(char* s) {
	int pos = 1;
	int i = 0;
	int count = 0;
	int num_true = 0;
	int end_index = 0;
	int num = 0;

	if (s == NULL)
		return num;

	while (s[i] != '\0' && num_true == 0) {
		if (s[i] == '-')
			pos*=-1;
		if (s[i] >= 48 && s[i] <= 57) {
			count++;
			num_true = 1;
		}
		i++;
	}

	if (num_true == 0)
		return num;

	while (s[i] >= 48 && s[i] <= 57) {
		count++;
		i++;
	}
	end_index=i-1;

	i = 0;
	while (i <= end_index) {
		if (s[i] >= 48 && s[i] <= 57) {
			num+=((s[i] - '0') * atoi_power(10, count-1));
			count--;
		}
		i++;
	}
	if (pos == -1)
		num*=-1;

	return num;
}
