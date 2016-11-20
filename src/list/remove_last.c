#include "../../include/list.h"

void* remove_last(struct s_node** node)
{
	struct s_node* i;
	void* e;
	if (node == NULL || *node == NULL)
	{
		return NULL;
	}
	else
	{
		i = *node;
		while (i->next != NULL)
		{
			i = i->next;
		}
		i->prev->next = NULL;
		e = i->elem;
		i->elem = NULL;
		i->next = NULL;
		i->prev = NULL;
		free(i);
		return e;
	}
}