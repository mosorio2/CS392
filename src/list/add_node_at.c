#include "../../include/list.h"

void add_node_at(struct s_node* node, struct s_node** head, int n)
{
	struct s_node* i;
	if (n <= 0)
	{
		n = 0;
	}
	if (node == NULL)
		return;
	if (node->elem == NULL)
		return;
	if (head == NULL || *head == NULL)
	{
		add_node(node, head);
		return;
	}
	else
	{
		i = *head;
		while ((i->next != NULL)&&(n > 1))
		{
			i = i->next;
			n--;
		}
		if (i->next == NULL)
		{
			append(node, head);
		}
		else
		{
			i->next->prev = node;
			node->next = i->next;
			i->next = node;
			node->prev = i;
		}
	}
}