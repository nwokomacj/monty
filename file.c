#include "monty.h"

/**
 * read_file - read the contents of a file
 * @fd: file descriptor
 * Return: a buffer containing file contents
 */
char *read_file(int fd)
{
	size_t file_size;
	char *buffer;
	struct stat filestat;

	fstat(fd, &filestat);
	file_size = filestat.st_size;
	buffer = malloc(file_size + 1);
	exit_on_malloc_fail(buffer);
	read(fd, buffer, file_size);
	buffer[file_size] = '\0';
	return (buffer);
}

/**
 * count_newlines - counts newlines inside a buffer
 * @buffer: a string buffer
 * Return: the number of '\n' characters in the buffer
 */
int count_newlines(char *buffer)
{
	int count = 0;
	char *p;

	for (p = buffer; *p != '\0'; p++)
		if (*p == '\n')
			count++;
	return (count);
}

/**
 * split_lines - split a string by newlines
 * @buffer: a string
 * Return: an array of lines found in the string
 */
char **split_lines(char *buffer)
{
	int num_lines, i;
	char **lines, *newline, *p;

	num_lines = count_newlines(buffer) + 1;
	lines = malloc(NPTRS(num_lines + 1));

	p = buffer;
	i = 0;
	while (i < num_lines)
	{
		newline = strchr(p, '\n');
		if (newline == NULL)
		{
			lines[i] = p;
			i++;
			break;
		}

		*newline = '\0';
		lines[i] = p;
		i++;
		p = newline + 1;
	}
	lines[i] = NULL;

	return (lines);
}

/**
 * get_tokens - split a string into tokens based on whitespace
 * @line: line to split
 * Return: anull-terminated array of at most 2 tokens
 */
char **get_tokens(char *line)
{
	char **tokens, *opcode, *arg;

	tokens = malloc(NPTRS(3));
	exit_on_malloc_fail(tokens);

	tokens[0] = NULL;
	tokens[1] = NULL;
	tokens[2] = NULL;

	if (!*line)
		return (tokens);

	opcode = strtok(line, "\t ");
	if (!opcode || !*opcode)
		return (tokens);
	if (strchr(opcode, ' '))
		*(strchr(opcode, ' ')) = '\0';
	if (strchr(opcode, '\t'))
		*(strchr(opcode, '\t')) = '\0';
	if (!*opcode)
		return (tokens);
	tokens[0] = opcode;

	arg = strtok(NULL, "\t ");
	if (!arg || !*arg)
		return (tokens);
	if (strchr(arg, ' '))
		*(strchr(arg, ' ')) = '\0';
	if (strchr(arg, '\t'))
		*(strchr(arg, '\t')) = '\0';
	if (!*arg)
		return (tokens);
	tokens[1] = arg;

	return (tokens);
}
