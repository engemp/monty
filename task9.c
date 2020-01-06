/**
 * modS -  computes the rest of div between the 2 and 1 items
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void modS(stack_t **stack, unsigned int number_line)
{
int mod = 0;
(void) stack;
(void) number_line;
if (!caw->head || !caw->head->next)
errorC(14);
if (caw->head->n == 0)
errorC(15);
mod = caw->head->next->n % caw->head->n;
caw->head->next->n = mod;
popS(NULL, 0);
}
