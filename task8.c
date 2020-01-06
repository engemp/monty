#include "monty.h"
/**
 * mulS - multiplies the top two elements of the stack
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void mulS(stack_t **stack, unsigned int number_line)
{
int mul = 0;
(void) stack;
(void) number_line;
if (!caw->head || !caw->head->next)
errorC(13);
mul = caw->head->next->n * caw->head->n;
caw->head->next->n = mul;
popS(NULL, 0);
}
