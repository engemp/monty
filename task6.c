#include "monty.h"
/**
 * subS - subtracts the first two items of the stack.
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void subS(stack_t **stack, unsigned int number_line)
{
int cont = 0;
(void) stack;
(void) number_line;
if (!caw->head || !caw->head->next)
errorC(10);
cont = caw->head->next->n - caw->head->n;
caw->head->next->n = cont;
popS(NULL, 0);
}
