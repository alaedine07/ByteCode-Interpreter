#include "monty.h"
/**
 * add_stack - add 2 top elements at the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void add_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->prev == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		if (*stack != NULL)
		{
			free_dlistint(*stack);
		}
		exit(EXIT_FAILURE);
	}

	(*stack)->prev->n += (*stack)->n;
	*stack = (*stack)->prev;
	free((*stack)->next);
	(*stack)->next = NULL;
}
/**
 * sub_stack - substract 2 top elements from the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void sub_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->prev == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		if (*stack != NULL)
		{
			free_dlistint(*stack);
		}
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n -= (*stack)->n;
	*stack = (*stack)->prev;
	free((*stack)->next);
	(*stack)->next = NULL;
}
/**
 * div_stack - divide 2 top elements from the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void div_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->prev == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		if (*stack != NULL)
		{
			free_dlistint(*stack);
		}
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		if (*stack != NULL)
		{
			free_dlistint(*stack);
		}
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n /= (*stack)->n;
	*stack = (*stack)->prev;
	free((*stack)->next);
	(*stack)->next = NULL;
}
/**
 * do_nothing - littearly do nothing
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
/**
 * mul_stack - multiply 2 top elements from the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void mul_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->prev == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free(hold_data.lineptr);
		free_array(hold_data.instructions);
		fclose(hold_data.fp);
		if (*stack != NULL)
		{
			free_dlistint(*stack);
		}
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n *= (*stack)->n;
	*stack = (*stack)->prev;
	free((*stack)->next);
	(*stack)->next = NULL;
}
