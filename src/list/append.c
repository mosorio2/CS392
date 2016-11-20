#include "../../include/list.h"

void append(struct s_node* node, struct s_node** head)
{
	struct s_node* i;
	if(node == NULL)
	{
		return;
	}
	if(node->elem == NULL)
	{
		return;
	}
	if((head == NULL) || (*head == NULL))
	{
		add_node(node, head);
	}
	else
	{
		i = *head;
		while (i->next != NULL)
		{
			i = i->next;
		}
		i->next = node;
		node->prev = i;
	}
}