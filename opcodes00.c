#include "monty.h"

/**
 * push - push a new value to the stack
 * @stack: the stack
 * @value: the value
 * Return: nothing
 */
void push(stack_t **stack, char *value)
{
	int i, throw = 0;

	if (!value)
		throw = 1;
	else if (!isdigit(value[0]) && value[0] != '-')
		throw = 1;
	else
		for (i = 1; value && value[i]; i++)
			if (!isdigit(value[i]))
			{
				throw = 1;
				break;
			}
	if (throw)
	{

		dprintf(2, "L%u: usage: push integer\n", state.lineno);
		monty_exit(EXIT_FAILURE);
	}

	if (state.stack_mode)
		add_node_top(stack, atoi(value));
	else
		add_node_bot(stack, atoi(value));
	state.length++;
}

/**
 * pall - print all values in the stack
 * @stack: the stack
 * @lineno: the opcode's line numbef
 * Return: nothing
 */
void pall(stack_t **stack, uint lineno)
{
	stack_t *temp;

	temp = *stack;
	(void)lineno;

	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: address of stack
 * @lineno: line number
 * Return: Nothing
 */
void pop(stack_t **stack, uint lineno)
{
	stack_t *temp;

	if (state.length == 0)

	{
		dprintf(2, "L%u: can't pop an empty stack\n", lineno);
		monty_exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	if (temp != NULL)
		temp->prev = NULL;
	*stack = temp;
	state.length--;
}

/**
 * pint - prints the top element of the stack
 * @stack: address of stack
 * @lineno: line number
 * Return: Nothing
 */
void pint(stack_t **stack, uint lineno)
{
	if (state.length == 0)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", lineno);
		monty_exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * nop - does nothing
 * @stack: address of stack
 * @lineno: line number
 * Return: Nothing
 */
void nop(stack_t **stack, uint lineno)
{
	(void)stack;
	(void)lineno;
}
