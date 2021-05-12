#ifndef _MONTY_H
#define _MONTY_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DELIM " $\n\t\a"
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
 * struct data_s - data instance
 * @lineptr: every line in the file
 * @fp: the file
 * @instructions: hold every line separated
 * Description: holds all data to be easily manipulated
*/
typedef struct data_s
{
    char *lineptr;
    char **instructions;
    FILE *fp;
} all_data_t;

extern all_data_t hold_data;

/* base functions */
void treat(unsigned int lb, stack_t **stack);
void parse_line(void);
/* helper functions */
void free_dlistint(stack_t *head);
void free_array(char **array);
/* instruction operations */
void print_dlistint(stack_t **stack, unsigned int line_number);
void add_dnodeint(stack_t **stack, unsigned int line_number);
void print_stack_top(stack_t **stack, unsigned int line_number);
void remove_top(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void sub_stack(stack_t **stack, unsigned int line_number);
void div_stack(stack_t **stack, unsigned int line_number);
void mul_stack(stack_t **stack, unsigned int line_number);
#endif