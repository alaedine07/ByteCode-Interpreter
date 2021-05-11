#include "monty.h"
/**
 * Globale data - store everything
 */
all_data_t hold_data;

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

void free_array(char **array)
{
    int i;

    for (i = 0; array[i]; i++)
    {
        free(array[i]);
    }
    free(array);
}
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
/* pushes an element in the stack */
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

void treat(unsigned int line_number, stack_t **stack)
{
    instruction_t inst[] = {
        {"push", add_dnodeint},
        {"pall", print_dlistint},
        {NULL, NULL}
    };
    int i = 0;
    int found = 0;
    
    while (inst[i].opcode != NULL && found == 0)
    {
        if (strcmp(inst[i].opcode,hold_data.instructions[0]) == 0)
        {
            /* execute function */
            inst[i].f(stack, line_number);
            found = 1;
        }
        i++;    
    }
    /* didn't find any command that matches */
    if (found == 0)
    {
        dprintf(2, "L%d: unknown instruction %s\n", line_number, hold_data.instructions[0]);
        free(hold_data.lineptr);
        free_array(hold_data.instructions);
        fclose(hold_data.fp);
        exit(EXIT_FAILURE);       
    }
}

void parse_line()
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

int main(int argc, char **argv)
{
    char *filename = NULL;
    size_t len;
    unsigned int line_number = 0;
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
        dprintf(2, "ERROR: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /* read the file content line by line */
    while (getline(&hold_data.lineptr, &len, hold_data.fp) != -1)
    {
        line_number++;
        /* split every line by delimiters */
        parse_line();
        printf("%s |  %s\n", hold_data.instructions[0], hold_data.instructions[1]);
        treat(line_number, &stack);
        free_array(hold_data.instructions);
    }
    fclose(hold_data.fp);
    free(hold_data.lineptr);
    /* no problem occured during treatment */
    free_dlistint(stack);
    return (EXIT_SUCCESS);
}
