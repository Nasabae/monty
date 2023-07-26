#include "monty.h"
/**
*ssa_f_sub- subtraction
*@head: stack head
*@counter: line_number
*Return: no return
*/
void ssa_f_sub(stack_t **head, unsigned int counter)
{
stack_t *aux;
int x, nodes;

aux = *head;
for (nodes = 0; aux != NULL; nodes++)
aux = aux->next;
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
fclose(bus.file);
free(bus.content);
ssa_free_stack(*head);
exit(EXIT_FAILURE);
}
aux = *head;
x = aux->next->n - aux->n;
aux->next->n = x;
*head = aux->next;
free(aux);
}
