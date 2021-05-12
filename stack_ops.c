#include "monty.h"
/**
 * print_dlistint - print all elements of the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void print_dlistint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
/**
 * add_dnodeint - add element at top of the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void add_dnodeint(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	/* no argument given to push */
	if (hold_data.instructions[1] == NULL)
	{
		dprintf(2, "L%d: usage: push integer\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(hold_data.instructions[1]);
	/* if stack is empty */
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->prev = *stack;
		(*stack)->next = new_node;
	}
	*stack = new_node;
}
/**
 * print_stack_top - print the element at the top of the stacl
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void print_stack_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * remove_top - remove_top of the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void remove_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if ((*stack)->prev != NULL)
	{
		(*stack)->prev->next = NULL;
		*stack = (*stack)->prev;
	}
	else
	{
		*stack = NULL;
	}
	free(temp);
}
/**
 * swap_stack - swap 2 elements at the top of stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void swap_stack(stack_t **stack, unsigned int line_number)
{
	int x;

	if ((*stack)->prev == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		exit(EXIT_FAILURE);
	}
	x = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = x;
}
