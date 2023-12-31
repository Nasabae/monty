#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct global_s - variables -> args, file, line content
 * @arg: value
 * @line: input line content
 * @file: pointer to monty file
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
char *arg;
FILE *file;
char *content;
int lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *ssa_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t ssa_getstdin(char **lineptr, int file);
char  *ssa_clean_line(char *content);
void ssa_f_push(stack_t **head, unsigned int number);
void ssa_f_pall(stack_t **head, unsigned int number);
void ssa_f_pint(stack_t **head, unsigned int number);
int  execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void ssa_free_stack(stack_t *head);
void ssa_f_pop(stack_t **head, unsigned int counter);
void ssa_f_swap(stack_t **head, unsigned int counter);
void ssa_f_add(stack_t **head, unsigned int counter);
void ssa_f_nop(stack_t **head, unsigned int counter);
void ssa_f_sub(stack_t **head, unsigned int counter);
void ssa_f_div(stack_t **head, unsigned int counter);
void ssa_f_mul(stack_t **head, unsigned int counter);
void ssa_f_mod(stack_t **head, unsigned int counter);
void ssa_f_pchar(stack_t **head, unsigned int counter);
void ssa_f_pstr(stack_t **head, unsigned int counter);
void ssa_f_rotl(stack_t **head, unsigned int counter);
void ssa_f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void ssa_addnode(stack_t **head, int n);
void ssa_addqueue(stack_t **head, int n);
void ssa_f_queue(stack_t **head, unsigned int counter);
void ssa_f_stack(stack_t **head, unsigned int counter);
void execute_file(stack_t* stack);
#endif
