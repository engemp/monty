#include "monty.h"
/**
 * pintS - prints the value at the top
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void pintS(stack_t **stack, unsigned int number_line)
{
	(void) stack;
	(void) number_line;

	if (caw->head == NULL)
		errorC(6);
	printf("%d\n", caw->head->n);
}
