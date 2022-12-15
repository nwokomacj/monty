#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: address of stack
 * @line_number: line number
 * Return: Nothing
*/
void add(stack_t **stack, uint line_number)
{

   stack_t *first, *second;
    int sum;

    
    if (state.length < 2)

    {
        printf(stderr, "L%d: can't add, stack too short\n", line_number);
        monty_exit(EXIT_FAILURE);
    }


    first = *stack;
    second = first->next;
    sum = first->n + second->n;
    second->n = sum;
    pop(stack, line_number)
}



/**
 * sub- subtracts the top element of the stack 
 * from the second top elements of the stack
 * @head: address of the stack
 * @line_number: line number
 * Return: Nothing
 */

void sub(stack_t **stack, uint line_number)
{
    stack_t *first, *second;
    int sum;

    
    if (state.length < 2)

    {
        printf(stderr, "L%d: can't sub, stack too short\n", line_number);
        monty_exit(EXIT_FAILURE);
    }


    first = *stack;
    second = first->next;
    sum = second->n - first->n;
    second->n = sum;
    pop(stack, line_number)
}