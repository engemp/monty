#include "monty.h"
/**
 * addS - adds the top two elements of the stack
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void addS(stack_t **stack, unsigned int number_line)
{
int cont = 0;
(void) stack;
(void) number_line;
if (!caw->head || !caw->head->next)
error_check(9);
cont = caw->head->n + caw->head->next->n;
caw->head->next->n = cont;
popS(NULL, 0);
}
