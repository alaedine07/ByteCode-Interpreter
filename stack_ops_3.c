#include "monty.h"
/**
 * mod_stack - mod 2 top elements from the stack
 * @stack: head of stack as doubly linked lists
 * @line_number: line number in instructions file
**/
void mod_stack(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->prev == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
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
	(*stack)->prev->n %= (*stack)->n;
	*stack = (*stack)->prev;
	free((*stack)->next);
	(*stack)->next = NULL;
}
