#include "monty.h"

state_t state = {
	.stack_mode = 1,
	.stack = NULL,
	.lineno = 1,
	.length = 0,
	.buffer = NULL,
	.lines = NULL,
	.tokens = NULL
};

int handle_opcode(char *opcode, char *value)
{
	int i;
	instruction_t handlers[] = {
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	
	if (!strcmp(opcode, "push"))
	{
		push(&(state.stack), value);
		return (1);
	}
	
	for (i = 0; handlers[i].f; i++)
	{
		if (!strcmp(handlers[i].opcode, opcode))
		{
			handlers[i].f(&(state.stack), state.lineno);
			return (1);
		}
	}
	
	return (0);
}


int main(int ac, char **av)
{
	int fd;
	char *buffer, **lines, *line, **tokens,
		*opcode, *arg;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		monty_exit(EXIT_FAILURE);
	}
	buffer = read_file(fd);
	close(fd);
	lines = split_lines(buffer);
	state.lines = lines;
	state.buffer = buffer;
	for (; lines[state.lineno - 1]; state.lineno++)
	{
		tokens = get_tokens(lines[state.lineno - 1]);
		opcode = tokens[0];
		arg = tokens[1];
		free(tokens);
		printf("opcode -> %s, value -> %s\n", opcode, arg);
		if (!opcode)
			continue;
		if (!handle_opcode(opcode, arg))
		{
			dprintf(2, "L%u: unknown instruction %s\n", state.lineno, opcode);
			monty_exit(EXIT_FAILURE);	
		}
	}
	monty_exit(EXIT_SUCCESS);
}
