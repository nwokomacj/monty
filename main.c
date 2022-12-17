#include "monty.h"

state_t state = {
	1, NULL,
	0, 1, NULL,
	NULL, NULL
};

/**
 * handle_opcode - call appropriate functiin for an opcode.
 * @opcode:an opcode
 * @value: opcode value ( rare )
 * Return: 1 if opcods is known else 0
 */
int handle_opcode(char *opcode, char *value)
{
	int i;
	instruction_t handlers[] = {
		{"pall", pall},
		{"pint", pint},
		{"pchar", pchar},
		{"pstr", pstr},
		{"swap", swap},
		{"add", add},
		{"div", div_},
		{"mul", mul},
		{"sub", sub},
		{"pop", pop},
		{"nop", nop},
		{"mod", mod},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
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

/**
 * main - entry point
 * @ac: argument count
 * @av: argument variables
 * Return: nothing
 */
int main(int ac, char **av)
{
	int fd;
	char *buffer, **lines, **tokens,
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
	exit_on_malloc_fail(lines);
	state.lines = lines;
	state.buffer = buffer;
	for (; lines[state.lineno - 1]; state.lineno++)
	{
		tokens = get_tokens(lines[state.lineno - 1]);
		opcode = tokens[0];
		arg = tokens[1];
		free(tokens);
		if (!opcode || opcode[0] == '#')
			continue;
		if (!handle_opcode(opcode, arg))
		{
			dprintf(2, "L%u: unknown instruction %s\n", state.lineno, opcode);
			monty_exit(EXIT_FAILURE);
		}
	}
	monty_exit(EXIT_SUCCESS);
	return (0);
}
