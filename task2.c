#include "monty.h"
/**
 * popS - removes the item at the top
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void popS(stack_t **stack, unsigned int number_line)
{
stack_t *tmp;
(void) stack;
(void) number_line;
if (caw->head == NULL)
errorC(7);
tmp = caw->head->next;
if (tmp != NULL)
tmp->prev = NULL;
free(caw->head);
caw->head = tmp;
}
