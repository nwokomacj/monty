#include "monty.h"
#include <errno.h>

/**
 * cleanup - perform clean up before program terminates
 * Return: nothing
 */
void cleanup(void)
{
	stack_t *tail, *temp;

	free(state.buffer);
	free(state.lines);
	free(state.tokens);

	tail = state.stack;
	if (!tail)
		return;
	while (tail->next)
		tail = tail->next;
	temp = tail->prev;
	while (temp != NULL)
	{
		free(tail);
		tail = temp;
		temp = tail->prev;
	}
	free(tail);
	state.stack = NULL;
}

/**
 * exit_on_malloc_fail - exit if malloc failz
 * @mem: addrezz of block
 * Returm: nothing
 */
void exit_on_malloc_fail(void *mem)
{
	if (mem == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		monty_exit(EXIT_FAILURE);
	}
}

/**
 * monty_exit - exit monty
 * @EXIT_STATUS: exit status
 * Return: nothing
 */
void monty_exit(int EXIT_STATUS)
{
	cleanup();
	exit(EXIT_STATUS);
}

