#include "monty.h"

/**
 * swap - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number
 * Return: Nothing
 */
void swap(stack_t **stack, uint line_number)
{
	int temp;
	stack_t *first, *second;

	if (state.length < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		monty_exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	temp = first->n;
	first->n = second->n;
	second->n = temp;
}

/**
 * pchar - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number                        * Return: Nothing
 */
void pchar(stack_t **stack, uint line_number)
{
	int chr;

	if (state.length < 1)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		monty_exit(EXIT_FAILURE);
	}
	chr = (*stack)->n;
	if (chr < 0 || chr > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		monty_exit(EXIT_FAILURE);
	}
	printf("%c\n", chr);
}

/**
 * pstr - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number                        * Return: Nothing
 */
void pstr(stack_t **stack, uint line_number)
{
	int chr;
	stack_t *temp;

	(void)line_number;
	temp = *stack;

	while (temp)
	{
		chr = temp->n;
		if (chr <= 0 || chr > 127)
			break;
		printf("%c", chr);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number                        * Return: Nothing
 */
void rotl(stack_t **stack, uint line_number)
{
	stack_t *top, *bot, *temp;

	(void)line_number;
	if (state.length < 2)
		return;
	top = *stack;
	temp = top->next;
	bot = top->next;

	while (bot->next)
		bot = bot->next;

	bot->next = top;
	top->prev = bot;
	temp->prev = NULL;
	top->next = NULL;
	*stack = temp;
}

/**
 * rotr - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number                        * Return: Nothing
 */
void rotr(stack_t **stack, uint line_number)
{
	stack_t *top, *bot, *temp;

	(void)line_number;
	if (state.length < 2)
		return;
	top = *stack;
	bot = top->next;

	while (bot->next)
		bot = bot->next;

	temp = bot->prev;

	bot->next = top;
	bot->prev = NULL;
	temp->next = NULL;
	top->prev = bot;
	*stack = bot;
}

