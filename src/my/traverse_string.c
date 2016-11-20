#include "../../include/list.h"

void traverse_string(struct s_node* head)
{
	struct s_node* node;
	if (head == NULL)
	{
		return;
	}
	node = head;
	while (node != NULL)
	{
		my_str((char*)node->elem);
		my_char(' ');
		node = node->next;
	}
	my_char('\n');
}