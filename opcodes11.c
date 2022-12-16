#include "monty.h"

/**
 * stack - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number                        * Return: Nothing
 */
void stack(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
	state.stack_mode = 1;
}

/**
 * queue - removes the top element of the stack
 * @stack: address of stack
 * @line_number: line number                        * Return: Nothing
 */
void queue(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
	state.stack_mode = 0;
}
