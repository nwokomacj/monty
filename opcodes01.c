#include "monty.h"

/**
  * div_ - divides the second element in the stack by the first
  * @stack: the stack
  * @line_number: line number
  * Return: Nothing
  */
void div_(stack_t **stack, uint line_number)
{
	stack_t *first, *second;
	int result;

	if (state.length < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		monty_exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	if (first->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		monty_exit(EXIT_FAILURE);
	}
	result = second->n / first->n;
	second->n = result;
	pop(stack, line_number);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: the stack
 * @line_number: line number
 * Return: Nothing
 */
void mul(stack_t **stack, uint line_number)
{
	stack_t *first, *second;
	int result;

	if (state.length < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		monty_exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	result = first->n * second->n;
	second->n = result;
	pop(stack, line_number);
}

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: line number
 * Return: Nothing
 */
void add(stack_t **stack, uint line_number)
{
	stack_t *first, *second;
	int result;

	if (state.length < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		monty_exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	result = first->n + second->n;
	second->n = result;
	pop(stack, line_number);
}

/**
 * sub - subtracts the top element of the stack
 *		from the second top elements of the stack
 * @stack: the stack
 * @line_number: line number
 * Return: Nothing
 */
void sub(stack_t **stack, uint line_number)
{
	stack_t *first, *second;
	int result;

	if (state.length < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		monty_exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	result = second->n - first->n;
	second->n = result;
	pop(stack, line_number);
}

/**
 * mod - performs modulo operation on the firdt two elements
 *		in the stack.
 * @stack: the stack
 * @line_number: line number
 * Return: Nothing
 */
void mod(stack_t **stack, uint line_number)
{
	stack_t *first, *second;
	int result;

	if (state.length < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		monty_exit(EXIT_FAILURE);
	}
	first = *stack;
	if (first->n == 0)
        {
                dprintf(2, "L%u: division by zero\n", line_number);
                monty_exit(EXIT_FAILURE);
        }
	second = first->next;
	result = second->n % first->n;
	second->n = result;
	pop(stack, line_number);
}
