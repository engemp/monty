#include "monty.h"

/**
 * fNodes - frees the stack
 * @head: pointer to the head of the list
 * Return: void
 */
void fNodes(stack_t *head)
{
if (head)
{
if (head->next != NULL)
fNodes(head->next);
free(head);
}
}

/**
 * fLine - frees the current line
 * Return: void
 */
void fLine(void)
{
if (caw->line)
{
free(caw->line);
caw->line = NULL;
}
}

/**
 * fToken - frees the current token
 * Return: void
 */
void fToken(void)
{
if (caw->opcode)
{
if (caw->opcode[0])
free(caw->opcode[0]);
if (caw->opcode[1])
free(caw->opcode[1]);
free(caw->opcode);
}
caw->opcode = NULL;
}
