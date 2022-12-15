#include "monty.h"
#include <errno.h>

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

void exit_on_malloc_fail(void *mem)
{
	if (mem == NULL && errno == ENOMEM)
		monty_exit(EXIT_FAILURE);
}

void monty_exit(int EXIT_STATUS)
{
	cleanup();
	exit(EXIT_STATUS);
}	

