#include "../../include/list.h"

struct s_node* node_at(struct s_node* head, int n)
{
	struct s_node* node;
	if (n <= 0)
	{
		n = 0;
	}
	if (head == NULL)
	{
		return NULL;
	}
	node = head;
	while ((node->next != NULL) || (n > 0))
	{
		node = node->next;
		n--;
	}
	return node;
}