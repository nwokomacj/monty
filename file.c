#include "monty.h"


/**
 * add_element - adds the top two elements of the stack
 * @head: address of stack
 * @line: line number
 * Return: Nothing
*/
void add_element(stack_t **head, int line),
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

