#include "../../include/list.h"

int count_s_nodes(struct s_node* head)
{
	int i;
	struct s_node* node;
	if (head == NULL)
	{
		return 0;
	}
	i = 0;
	node = head;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return i;
}