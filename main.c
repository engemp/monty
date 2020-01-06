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
error(1);
caw->fptr = fopen(caw->name_file, "r");
if (caw->fptr == NULL)
error(2);
while (getline(&caw->line, &size, caw->fptr) != -1)
{
caw->number_line++;
caw->opcode = malloc(sizeof(char *) * 2);
if (caw->opcode == NULL)
error(3);
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
token = strtok(line, " '\n'");
for (i = 0; token != NULL && i < 2; i++)
{
caw->opcode[i] = strdup(token);
if (caw->opcode[i] == NULL)
error(3);
token = strtok(NULL, " '\n'");
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
{NULL, NULL}
};

if (caw->opcode[0] == NULL)
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
error(5);
}

void error(unsigned int errorN)
{
if (errorN == 1)
printf("USAGE: monty file\n");
if (errorN == 2)
printf("Error: Can't open file %s\n", caw->name_file);
if (errorN == 3)
printf("Error: malloc failed");
if (errorN == 4)
printf("L%d: usage: push integer\n", caw->number_line);
if (errorN == 5)
printf("L%d: unknown instruction %s\n", caw->number_line, caw->opcode[0]);
fLine();
fNodes(caw->head);
fToken();
if (caw->fptr)
fclose(caw->fptr);
exit(EXIT_FAILURE);
}
