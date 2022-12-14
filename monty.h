#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

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

typedef struct state
{
	int stack_mode;
	size_t length;
	uint line_no;
	void *buffer;
	void *lines;
	void *tokens;
} state;

char *read_file(int fd);
char **split_lines(char *buffer);
char **get_tokens(char *line);

int print_node(stack_t *node, int ascii_val);
int print_nodes(stack_t *node, int ascii_val);
void free_stack(stack_t *node);


void push(stack_t **stack, int value);
void enqueue(stack_t **stack, int value);
void stack_mode(void);
void queue_mode(void);


void pop(stack_t **stack, uint line_number);
void pint(stack_t **stack, uint line_number);
void pall(stack_t **stack, uint line_number);
void pchar(stack_t **stack, uint line_number);
void pstring(stack_t **stack, uint line_number);
void swap(stack_t **stack, uint line_number);
void nop(stack_t **stack, uint line_number);
void add(stack_t **stack, uint line_number);
void sub(stack_t **stack, uint line_number);
void mul(stack_t **stack, uint line_number);
void div(stack_t **stack, uint line_number);
void mod(stack_t **stack, uint line_number);
void rotl(stack_t **stack, uint line_number);
void rotr(stack_t **stack, uint line_number);



extern state *state;
extern stack *stack;





#endif
