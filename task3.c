#include "monty.h"
/**
 * swapS - swaps the two items at the top
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void swapS(stack_t **stack, unsigned int number_line)
{
int i = 0;
(void) stack;
(void) number_line;
if (caw->head && caw->head->next)
{
i = caw->head->n;
caw->head->n = caw->head->next->n;
caw->head->next->n = i;
}
else
errorC(8);
}
