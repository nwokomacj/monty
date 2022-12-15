#include "monty.h"

/**
 * mul - multiplies the second element of the stack by the top
 * @stack: address of the stack
 * @line_line: line number
 * Return: Nothing
*/
void mul(stack_t **stack, uint line_number)
{
    stack_t *first, *second;
    int sum;

    
    if (state.length < 2)

    {
        printf(stderr, "L%d: can't mul, stack too short\n", line_number);
        monty_exit(EXIT_FAILURE);
    }


    first = *stack;
    second = first->next;
    sum = first->n * second->n;
    second->n = sum;
    pop(stack, line_number)

}

