#include "../../include/list.h"

void* remove_node(struct s_node** node)
{
	void* e;
	struct s_node* i;
	if (node == NULL || *node == NULL)
	{
		return NULL;
	}
	else
	{
		i = *node;
		*node = (*node)->next;
		e = i->elem;
		i->elem = NULL;
		i->next = NULL;
		i->prev = NULL;
		free(i);
		return e;
	}
}