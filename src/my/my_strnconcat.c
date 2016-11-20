#include "../../include/my.h"

char* my_strnconcat(char* a, char* b, int n) {
	char* dst = NULL;
	int len_a = my_strlen(a);
	int len_b = my_strlen(b);
	int f_len = len_a + len_b;
	char* a_new = NULL;
	char* b_new = NULL;
	char* temp = NULL;

	if (a == NULL && b == NULL)
		return NULL;
	if (n <= 0) {
		a_new = (char*) malloc (len_a * sizeof(char) + 1);
		a_new = my_strcpy(a_new, a);
		return a_new;
	}
	
	if (a == NULL) {
		if (n > len_b)
			n = len_b;
		temp = (char*) malloc (n * sizeof(char) + 1);
		b_new = (char*) malloc (n * sizeof(char) + 1);
		b_new = my_strncpy(temp, b, n);
		return b_new;
	}
	if (b == NULL) {
		dst = (char*) malloc (len_a * sizeof(char) + 1);
		return my_strcpy(dst, a);
	}

	if (n >= len_b) {
		dst = (char*) malloc (f_len * sizeof(char) + 2);
		return my_strcat(my_strcpy(dst, a), b);
	}
	else {
		temp = (char*) malloc (n * sizeof(char) + 1);
		b_new = (char*) malloc (n * sizeof(char) + 1);
		b_new = my_strncpy(temp, b, n);
		a_new = (char*) malloc ((len_a + n) * sizeof(char) + 1);
		a_new = my_strcpy(a_new, a);
		return my_strcat(my_strcpy(a_new, a), b_new);
	}

}
