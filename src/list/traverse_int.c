#include "../../include/list.h"

void traverse_int(struct s_node* head)
{
	struct s_node* node;
	if (head == NULL)
	{
		return;
	}
	node = head;
	while (node != NULL)
	{
		my_int(*((int*)node->elem));
		my_char(' ');
		node = node->next;
	}
	my_char('\n');
}