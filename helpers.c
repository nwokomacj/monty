#include "monty.h"

/**
 * add_node_top - add node to the top of the list (push)
 * @head: address of the head of the list
 * @n: data for the new node
 * Return: the newly created node
 */
stack_t *add_node_top(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	exit_on_malloc_fail(new);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * add_node_bot - add node to the end of the list (enqueue)
 * @head: address of the head of the lis
 * @n: data for the new node
 * Return: the newly created node
 */
stack_t *add_node_bot(stack_t **head, int n)
{
	stack_t *tail, *new;

	new = malloc(sizeof(stack_t));
	exit_on_malloc_fail(new);
	new->n = n;
	new->next = NULL;
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
