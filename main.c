#include "monty.h"
caw_t *caw;
/**
 * main - entry point
 * @argv: arguments received by the program
 * @argc: number of arguments received by the program
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
caw_t tmp = {NULL, 0, NULL, NULL, NULL, NULL};
size_t size = 0;
caw = &tmp;
caw->name_file = argv[1];
if (argc != 2)
errorC(1);
caw->fptr = fopen(caw->name_file, "r");
if (!caw->fptr)
errorC(2);
while (getline(&caw->line, &size, caw->fptr) != -1)
{
caw->number_line++;
caw->opcode = malloc(sizeof(char *) * 2);
if (caw->opcode == NULL)
errorC(3);
tokenizer(caw->line);
command();
fToken();
}
fLine();
fNodes(caw->head);
fToken();
fclose(caw->fptr);
return (0);
}

/**
 * tokenizer - get tokes from the line passed by arguments
 * @line: line passed by arguments
 * Return: void
 */
void tokenizer(char *line)
{
int i = 0;
char *token = NULL;
caw->opcode[0] = NULL;
caw->opcode[1] = NULL;
token = strtok(line, "\t\n ");
for (i = 0; token != NULL && i < 2; i++)
{
caw->opcode[i] = strdup(token);
if (caw->opcode[i] == NULL)
errorC(3);
token = strtok(NULL, "\t\n ");
}
}



/**
 * command - look for the command and execute it.
 * Return: void
 */
void command(void)
{
unsigned int i;
instruction_t command[] = {
{"push", pushOp},
{"pall", pallOp},
{"pint", pintS},
{"pop", popS},
{"swap", swapS},
{"add", addS},
{"nop", nopS},
{NULL, NULL}
};

if (!caw->opcode[0])
return;
for (i = 0; command[i].opcode; i++)
{
if (strcmp(caw->opcode[0], command[i].opcode) == 0)
{
command[i].f(NULL, 0);
break;
}
}
if (command[i].opcode == NULL)
errorC(5);
}

/**
 * errorC - shows the error according to the failure
 * @errorN: number asociated to the error
 * Returns: void and EXIT_FAILURE
 */
void errorC(unsigned int errorN)
{
if (errorN == 1)
dprintf(STDERR_FILENO, "USAGE: monty file\n");
if (errorN == 2)
dprintf(STDERR_FILENO, "Error: Can't open file %s\n", caw->name_file);
if (errorN == 3)
dprintf(STDERR_FILENO, "Error: malloc failed\n");
if (errorN == 4)
dprintf(STDERR_FILENO, "L%d: usage: push integer\n", caw->number_line);
if (errorN == 5)
dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", caw->number_line, caw->opcode[0]);
if (errorN == 6)
dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", caw->number_line);
if (errorN == 7)
dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", caw->number_line);
if (errorN == 8)
dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", caw->number_line);
if (errorN == 9)
dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", caw->number_line);
fLine();
fNodes(caw->head);
fToken();
if (caw->fptr)
fclose(caw->fptr);
exit(EXIT_FAILURE);
}
