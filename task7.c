#include "monty.h"
/**
 * divS - divides the two items at the top of the stack
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void divS(stack_t **stack, unsigned int number_line)
{
int res = 0;
(void) stack;
(void) number_line;
if (!caw->head || !caw->head->next)
errorC(11);
if (caw->head->n == 0)
errorC(12);
res = caw->head->next->n / caw->head->n;
caw->head->next->n = res;
popS(NULL, 0);
}
