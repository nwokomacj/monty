#include "monty.h"

/**
  * div_ - divides the second element by the first from the stack
  * @stack: address of the stack
  * @line_line: line number
  * Return: Nothing
 */
void div_(stack_t **stack, uint line_number)
{
    stack_t *first, *second;
    int sum;

    
    if (state.length < 2)

    {
        dprintf(2, "L%d: can't div, stack too short\n", line_number);
        monty_exit(EXIT_FAILURE);
    }


    first = *stack;
    second = first->next;
    sum = second->n / first->n;
    second->n = sum;
    pop(stack, line_number);

}
