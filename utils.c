#include "monty.h"
/**
 * free_dlistint - free doubly linked lists
 * @head: head of linked lists
**/
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->prev;
		free(temp);
	}
	free(head);
}
/**
 * free_array - free array of pointers
 * @array: array of pointers
**/
void free_array(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
	}
	free(array);
}
/**
 * check_comment - check if first nonspace character is #
 * Return: True or False
**/
int check_comment(void)
{
	size_t i = 0;

	while (isspace(hold_data.lineptr[i]) && i < strlen(hold_data.lineptr) - 1)
	{
		i++;
	}
	if (hold_data.lineptr[i] == '#' || hold_data.lineptr[i] == '\n')
	{
		return (1);
	}
	return (0);
}
