#include "monty.h"

stack_t *add_node_top(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}


stack_t *add_node_bot(stack_t **head, int n)
{
	stack_t *tail, *new;

	new = malloc(sizeof(stack_t));
	exit_on_malloc_fail(new);
	new->n = n;
	tail = *head;

	if (tail)
	{
		while (tail->next)
			tail = tail->next;
		tail->next = new;
	}
	new->prev = tail;
	if (!*head)
		*head = new;
	return (new);
}

stack_t *peek_top()
{
	return (state.stack);
}


stack_t *peek_bot()
{
	stack_t *temp = peek_top();
	
	while (temp && temp->next)
		temp = temp->next;
		
	return (temp);
}
