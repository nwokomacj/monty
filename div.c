/**
  * div_element - divides the second element by the first from the stack
  * @head: address of the stack
  * @line: line number
  * Return: Nothing
 */
void div_element(stack_t **head, int line),
{
    stack *new;
    int sum

    new = malloc(sizeof(stact_t))
    if (*stack == NULL)

    {
        printf(stderr, "L%d: can't div, stack too short\n", line);
        exit(EXIT_FAILURE)
    }

   if (top->n == 0)
   {
    printf(stderr, "L%d: division by zero\n", line);
   }
   new = top->prev;
   sum = new->n / top->n;
   top = new;

}