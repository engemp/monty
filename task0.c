#include "monty.h"

/**
 * pushOp - pushes an item into the stack
 * @stack: double pointer
 * @number_line: number of the line
 * Returns: void
 */
void pushOp(stack_t **stack, unsigned int number_line)
{
stack_t *node = NULL;
unsigned int i = 0;
unsigned int flagp = 0;
unsigned int flagn = 0;
char *compare;
compare = caw->opcode[1];
(void) stack;
(void) number_line;
node = addNode();
if (node == NULL)
error(3);
if (compare != NULL)
{
if (compare[0] == '-')
{
i++;
flagn = 1;
flagp = 1;
}
while (compare[i])
{
if (isdigit(compare[i]) == 0)
{
flagp = 1;
break;
}
i++;
flagp = 0;
}
if (flagp == 0)
{
if (flagn == 1)
compare += 1;
node->n = atoi(compare);
if (flagn == 1)
node->n *= -1;
return;
}
}
error(4);
}

/**
 * pallOp - prints every item in the stack
 * @stack: double pointer
 * @number_line: number of the line
 * Return: void
 */
void pallOp(stack_t **stack, unsigned int number_line)
{
stack_t *tmp = caw->head;
(void) stack;
(void) number_line;
if (tmp == NULL)
return;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}

/**
 * addNode - adds a node
 * Return: the node added
 */
stack_t *addNode(void)
{
stack_t *node;
stack_t *tmp = caw->head;
node = malloc(sizeof(stack_t));
if (node == NULL)
return (NULL);
node->n = 0;
if (tmp == NULL)
node->next = NULL;
else
node->next = tmp;
node->prev = NULL;
if (tmp)
tmp->prev = node;
caw->head = node;
return (node);
}
