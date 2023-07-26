#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: pointer to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
instruction_t opst[] = {
{"push", ssa_f_push}, {"pall", ssa_f_pall}, {"pint", ssa_f_pint},
{"pop", ssa_f_pop},
{"swap", ssa_f_swap},
{"add", ssa_f_add},
{"nop", ssa_f_nop},
{"sub", ssa_f_sub},
{"div", ssa_f_div},
{"mul", ssa_f_mul},
{"mod", ssa_f_mod},
{"pchar", ssa_f_pchar},
{"pstr", ssa_f_pstr},
{"rotl", ssa_f_rotl},
{"rotr", ssa_f_rotr},
{"queue", ssa_f_queue},
{"stack", ssa_f_stack},
{NULL, NULL}
};
unsigned int z = 0;
char *op;

op = strtok(content, " \n\t");
if (op && op[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opst[z].opcode && op)
{
if (strcmp(op, opst[z].opcode) == 0)
{	opst[z].f(stack, counter);
return (0);
}
z++;
}
if (op && opst[z].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
fclose(file);
free(content);
ssa_free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}
