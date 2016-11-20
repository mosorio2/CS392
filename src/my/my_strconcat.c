#include "../../include/my.h"

char* my_strconcat(char* a, char* b) {
	char* dst = NULL;
	int len_a = my_strlen(a); 
	int len_b = my_strlen(b);
	int f_len = len_a + len_b;

	if (a == NULL && b == NULL)
		return NULL;
	
	if (a == NULL) {
		dst = (char*) malloc (len_b * sizeof(char) + 1);
		return my_strcpy(dst, b);
	}
	if (b == NULL) {
		dst = (char*) malloc (len_a * sizeof(char) + 1);
		return my_strcpy(dst, a);
	}

	dst = (char*) malloc (f_len * sizeof(char) + 2);
	return my_strcat(my_strcpy(dst, a), b);
}
