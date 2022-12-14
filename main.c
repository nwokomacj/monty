#include "monty.h"


int main(int ac, char **av)
{
	int fd;
	char *buffer;
	char **lines, *line, **tokens;
	int x, y, z;
	
	fd = open("test.m", O_RDONLY);
	buffer = read_file(fd);
	lines = split_lines(buffer);
	for (x = 0; lines[x]; x++)
	{
		tokens = get_tokens(lines[x]);
		for (y = 0; tokens[y]; y++)
			printf("%s ", tokens[y]);
		printf("\n");
	}
	//printf("%s\n", buffer);
	return (0);
}
