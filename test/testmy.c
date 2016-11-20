#include "../include/my.h"

int main(int argc, char**argv)
{
char test[] = "hello";
char other[] = "water";
my_str("hello");
my_int(15);
my_int(my_strlen("hello"));
my_num_base(-9, "RTFM");
my_alpha();
my_digits();
my_str(my_strindex(test, 'l'));
my_str(my_strrindex(test, 'l'));
my_revstr(test);
my_str(test);
my_int(my_strfind("hello", 'e'));
my_int(my_strrfind("hello", 'l'));
my_int(my_strcmp("heo", "hello"));
my_int('h');
my_int(my_strncmp("hello", "hi", 3));
my_str(my_strcpy(test, other));
return 0;
}