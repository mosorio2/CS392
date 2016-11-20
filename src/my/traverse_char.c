#include "../../include/list.h"

void traverse_char(struct s_node* head)
{
	struct s_node* node;
	if (head == NULL)
	{
		return;
	}
	node = head;
	while (node != NULL)
	{
		my_char(*((char*)node->elem));
		my_char(' ');
		node = node->next;
	}
	my_char('\n');
}