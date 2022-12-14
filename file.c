#include "monty.h"

/**
* 
*
*/

char *read_file(int fd)
{
    char *str;
    struct stat statbuf;
    fstat(fd, &statbuf);

    str = malloc(statbuf.st_size +1);
    read(fd, str, statbuf.st_size);
    str[statbuf.st_size] = '\0';
    return (str);
}


/**
 * add_element - adds the top two elements of the stack
 * @head: address of stack
 * @line: line number
 * Return: Nothing
*/
void add_elemet(stack_t **head, int line),
{
    stack_t *new; 
    int sum;

    new = malloc(sizeof(stack_t))
    if (*stack == NULL)

    {
        printf(stderr, "%d: Can't add, stack too short\n", line);
        exit (EXIT FAILURE);

    }

    new = top->prev;
    sum = new->n + top->n;
    new-> = sum;
    top = new;
}


/**
 * sub_element - subtracts the top element of the stack 
 * from the second top elements of the stack
 * @head: address of the stack
 * @line: line number
 * Return: Nothing
 */

void sub_element(stack_t **head, int line),
{
    stack *new;
    int sum;

    new = malloc(sizeof(stack_t))
    if (*stack == NULL)

    {
        printf(stderr, "%d: Can't sub., stack too short\n", line):
        exit(EXIT FAILURE);
    }

    new = top->prev;
    sum = new->n - top->n;
    new-> =  sum;
    top = new;
}
 
 /**
  * div_element - divides the second element by the first from the stack
  * @head: address of the stack
  * @line: line number
  * Return: Mothing
 */
void div_element(stack_t **head, int line),
{
    stack *new;
    int sum

    new = malloc(sizeof(stact_t))
    if (*stack == NULL)

    {
        printf(stderr, "%d: can't divide, stack too short\n", line):
        exit(EXIT FAILURE)
    }

    
}