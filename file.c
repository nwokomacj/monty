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
 * split_lines - split a string by newlines
 * @buffer: a string
 * Return: an array of lines found in the string
 */
char **split_lines(char *buffer)
{
	uint num_lines = 1, i;
	char **lines, *line;
	
	for (i = 0; buffer[i]; i++)
		if (buffer[i] == '\n')
			num_lines++;
	
	lines = malloc(NPTRS(num_lines + 1));
	exit_on_malloc_fail(lines);
		
	line = strtok(buffer, "\n");

	for (i = 0; i < num_lines; i++)
	{
		lines[i] = line;
		line = strtok(NULL, "\n");
	}
	lines[i] = NULL;
	return (lines);
}

/**
 * get_tokens - split a string into tokens based on whitespace
 * @lines: line to split
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
