#include "../../include/list.h"

void add_elem(void* elem, struct s_node** head)
{
	add_node(new_node(elem, NULL, NULL), head);
}