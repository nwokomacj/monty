#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>

#define NPTRS(size) (sizeof(void *) * (size))

typedef unsigned int uint;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, uint line_number);
} instruction_t;

/**
 * struct state - global state
 * @stack_mode: mode of insertion
 * @stack: a list
 * @length: length of stack
 * @lineno: cutrent executing line number
 * @buffer: a buffer
 * @lines: an array of lines
 * @tokens: an array of tokens
 */
typedef struct state
{
	int stack_mode;
	stack_t *stack;
	size_t length;
	uint lineno;
	void *buffer;
	void *lines;
	void *tokens;
} state_t;

char *read_file(int fd);
char **split_lines(char *buffer);
char **get_tokens(char *line);

void cleanup(void);
void exit_on_malloc_fail(void *mem);
void monty_exit(int EXIT_STATUS);

stack_t *add_node_bot(stack_t **head, int n);
stack_t *add_node_top(stack_t **head, int n);



void push(stack_t **stack, char *value);

void pop(stack_t **stack, uint line_number);
void pint(stack_t **stack, uint line_number);
void pall(stack_t **stack, uint line_number);
void pchar(stack_t **stack, uint line_number);
void pstr(stack_t **stack, uint line_number);
void swap(stack_t **stack, uint line_number);
void nop(stack_t **stack, uint line_number);
void add(stack_t **stack, uint line_number);
void sub(stack_t **stack, uint line_number);
void mul(stack_t **stack, uint line_number);
void div_(stack_t **stack, uint line_number);
void mod(stack_t **stack, uint line_number);
void rotl(stack_t **stack, uint line_number);
void rotr(stack_t **stack, uint line_number);
void stack(stack_t **stack, uint line_number);
void queue(stack_t **stack, uint line_number);

extern state_t state;

#endif
