#include "../../include/list.h"

void* elem_at(struct s_node* head, int n)
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
	if (head->elem == NULL)
	{
		return NULL;
	}
	node = head;
	while ((node->next != NULL) || (n > 0))
	{
		node = node->next;
		n--;
	}
	if (node->next == NULL)
	{
		return node;
	}
	else
	{
		return node->elem;
	}
}