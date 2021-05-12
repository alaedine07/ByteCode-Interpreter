#include "monty.h"

all_data_t hold_data;
/**
 * treat - compare to available instructions
 * @lb: number of lines corresponding to the instruction
 * @stack: stack as doubly linked lists
**/
void treat(unsigned int lb, stack_t **stack)
{
	instruction_t inst[] = {
		{"push", add_dnodeint},
		{"pall", print_dlistint},
		{"pint", print_stack_top},
		{"pop", remove_top},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", do_nothing},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", char_stack},
		{NULL, NULL}
	};
	int i = 0;
	int found = 0;

	while (inst[i].opcode != NULL && found == 0)
	{
		if (strcmp(inst[i].opcode, hold_data.instructions[0]) == 0)
		{
			/* execute function */
			inst[i].f(stack, lb);
			found = 1;
		}
		i++;
	}
	/* didn't find any command that matches */
	if (found == 0)
	{
		dprintf(2, "L%d: unknown instruction %s\n", lb, hold_data.instructions[0]);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		exit(EXIT_FAILURE);
	}
}
/**
 * parse_line - tokenization process
**/
void parse_line(void)
{
	int buffsize = 1024;
	char *duplicated;
	char *word;
	int i = 0;

	duplicated = strdup(hold_data.lineptr);
	hold_data.instructions = malloc(sizeof(char *) * buffsize);
	if (hold_data.instructions == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	word = strtok(duplicated, DELIM);
	for (i = 0; word != NULL; i++)
	{
		hold_data.instructions[i] = strdup(word);
		word = strtok(NULL, DELIM);
	}
	hold_data.instructions[i] = NULL;
	free(duplicated);
}
/**
 * main - open file and read line by line
 * @argc: number of arguments
 * @argv: arguments
 * Return: Success or Failure
**/
int main(int argc, char **argv)
{
	char *filename = NULL;
	size_t len;
	unsigned int line_number = 0;
	int v = 0;
	/* this always points to the top of the stack */
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	hold_data.fp = fopen(filename, "r");
	if (hold_data.fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&hold_data.lineptr, &len, hold_data.fp) != -1)
	{
		line_number++;
		if (*hold_data.lineptr != '\n')
		{
			v = check_comment();
			if (!v)
			{
				parse_line();
				treat(line_number, &stack);
				free_array(hold_data.instructions);
			}
		}
	}
	fclose(hold_data.fp);
	free(hold_data.lineptr);
	free_dlistint(stack);
	return (EXIT_SUCCESS);
}
