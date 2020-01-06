#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct caw_s - global variable
 * @head: pointer to the head of the list
 * @number_line: number of the line in the file
 * @line: the line from the file
 * @opcode: token of the opcode
 * @name_file: file name passed
 * @fptr: pointer to the file
 */
typedef struct caw_s
{
stack_t *head;
unsigned int number_line;
char *line;
char *name_file;
char **opcode;
FILE *fptr;
} caw_t;

extern caw_t *caw;

void tokenizer(char *line);
void command(void);
void fNodes(stack_t *head);
void fLine(void);
void fToken(void);
void pushOp(stack_t **stack, unsigned int number_line);
void pallOp(stack_t **stack, unsigned int number_line);
stack_t *addNode(void);
void errorC(unsigned int errorN);
void pintS(stack_t **stack, unsigned int number_line);
void popS(stack_t **stack, unsigned int number_line);
void swapS(stack_t **stack, unsigned int number_line);
void addS(stack_t **stack, unsigned int number_line);
void nopS(stack_t **stack, unsigned int number_line);
void subS(stack_t **stack, unsigned int number_line);
void divS(stack_t **stack, unsigned int number_line);
void mulS(stack_t **stack, unsigned int number_line);
void modS(stack_t **stack, unsigned int number_line);
#endif /* _MONTY_H_ */
