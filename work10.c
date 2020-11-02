#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "work10.h"

void print_list(struct node *Bob)
{
    printf("[");
    while (Bob)
    {
        printf("{%d, %s}", Bob->id, Bob->name);
        Bob = Bob->next;
    }
    printf("]\n");
}

struct node *create_node(int i, char n[200])
{
    struct node *dan;
    dan = malloc(sizeof(struct node));

    strncpy(dan->name, n, sizeof(dan->name) - 1);
    dan->id = i;
    dan->next = NULL;
    return dan;
}

struct node *free_node(struct node *current)
{
    free(current);
    return NULL;
}

struct node *insert_front(struct node *current, int num, char *n)
{
    struct node *New = create_node(num, n);
    New->next = current;
    return New;
}

struct node *free_list(struct node *current)
{
    struct node *placeholder = current;
    while (placeholder)
    {
        placeholder = current->next;
        current = free_node(current);
        current = placeholder;
    }
    return current;
}

struct node *remove_node(struct node *front, int data, char *n)
{
    struct node *placeholder = front->next;
    if (front->id == data && strcmp(n, front->name) == 0) //0th term only
    {
        front = placeholder;
        return front;
    }
    struct node *beginning = front;
    placeholder = front->next;

    while (placeholder) //1st and beyond terms
    {
        if (placeholder->id == data && strcmp(n, placeholder->name) == 0)
        {
            front->next = placeholder->next;
            free_node(placeholder);
            return beginning;
        }
        front = placeholder;
        placeholder = placeholder->next;
    }
    return front;
}