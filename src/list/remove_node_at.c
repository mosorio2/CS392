#include "../../include/list.h"

void* remove_node_at(struct s_node** head, int n)
{
	struct s_node* i;
	void* e;
	if (n <= 0)
	{
		remove_node(head);
	}
	if (head == NULL || *head == NULL)
	{
		remove_node(head);
		return NULL;
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
			return remove_last(head);
		}
		else
		{
			e = i->elem;
			i->prev->next = i->next;
			i->next->prev = i->prev;
			i->elem = NULL;
			i->next = NULL;
			i->prev = NULL;
		}
		free(i);
		return e;
	}
}