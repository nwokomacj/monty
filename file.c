#include "monty.h"


/**
 * add_element - adds the top two elements of the stack
 * @stack: address of stack
 * @line_number: line number
 * Return: Nothing
*/
void add_element(stack_t **stack, uint line_number),
{

    if ( state->length < 2)

    {
        dprintf(2, "L%d: Can't add, stack too short\n", line_number);
        exit (EXIT_FAILURE);

    }
    ((*stack)->next->n = (*stack)->n + (*stack)->next->n);
    pop(stack, line_number);
    new = top->prev;
    sum = new->n + top->n;
    new->n = sum;
    top = new;
}


/**
 * sub_element - subtracts the top element of the stack 
 * from the second top elements of the stack
 * @head: address of the stack
 * @line_number: line number
 * Return: Nothing
 */

void sub(stack_t **stack, uint line_number),
{
    stack *new;
    int sum;

    new = malloc(sizeof(stack_t))
    if (*stack == NULL)

    {
        printf(stderr, "L%d: Can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    new = top->prev;
    sum = new->n - top->n;
    new->n =  sum;
    top = new;
}
 


char *read_file(int fd)
{
	size_t file_size;
	char *buffer;
	struct stat filestat;
	
	fstat(fd, &filestat);
	file_size = filestat.st_size;
	buffer = malloc(file_size + 1);
	read(fd, buffer, file_size);
	buffer[file_size] = '\0';
	return (buffer);
}


char **split_lines(char *buffer)
{
	uint num_lines = 0;
	int i;
	char **lines, *line;
	
	for (i = 0; buffer[i]; i++)
		if (buffer[i] == '\n')
			num_lines++;
	
	lines = malloc(NPTRS(num_lines + 1));
	if (!lines)
		return (NULL);
		
	line = strtok(buffer, "\n");

	for (i = 0; i < num_lines; i++)
	{
		lines[i] = line;
		line = strtok(NULL, "\n");
	}
	lines[i] = NULL;
	return (lines);
}

char **get_tokens(char *line)
{
	char **tokens, *opcode, *arg;
	
	tokens = malloc(NPTRS(3));
	if (!tokens)
		return (NULL);
	
	tokens[0] = NULL;
	tokens[1] = NULL;
	tokens[2] = NULL;
	
	opcode = strtok(line, "\t ");
	if (!opcode || !*opcode)
		return (tokens);
	if (strchr(opcode, ' '))
	       *(strchr(opcode, ' ')) = '\0';
	if (strchr(opcode, '\t'))
               *(strchr(opcode, '\t')) = '\0';
	tokens[0] = opcode;

	arg = strtok(NULL, "\t ");
        if (!arg || !*arg)
                return (tokens);
        if (strchr(arg, ' '))
               *(strchr(arg, ' ')) = '\0';
        if (strchr(arg, '\t'))
               *(strchr(arg, '\t')) = '\0';
	tokens[1] = arg;
	
	return (tokens);
}

 
