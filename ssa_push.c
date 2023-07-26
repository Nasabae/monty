#include "monty.h"
/**
* ssa_f_push - add node to the stack
* @head: stack head
* @counter: line_number
* Return: no return
*/
void ssa_f_push(stack_t **head, unsigned int counter)
{
int x, z = 0, flag = 0;

if (bus.arg)
{
if (bus.arg[0] == '-')
z++;
for (; bus.arg[z] != '\0'; z++)
{
if (bus.arg[z] > 57 || bus.arg[z] < 48)
flag = 1; }
if (flag == 1)
{ fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE); }}
else
{ fprintf(stderr, "L%d: usage: push integer\n", counter);
fclose(bus.file);
free(bus.content);
free_stack(*head);
exit(EXIT_FAILURE); }
x = atoi(bus.arg);
if (bus.lifi == 0)
addnode(head, x);
else
addqueue(head, x);
}
