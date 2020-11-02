#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "work10.h"

int main()
{
    struct node *a, *b, *c, *d;
    a = create_node(101, "A");
    b = create_node(102, "B");
    c = create_node(103, "C");

    a->next = b;
    b->next = c;
    printf("Printing nodes a, b, c\n");
    print_list(a);
    
    d = insert_front(a, 99, "D");
    printf("Printing node d and it's linked list\n");
    print_list(d);
    //print_list(a); //test to make sure d was actually removed from the list

    d = remove_node(d, 99, "D");
    printf("Removed node d\n");
    print_list(d);
    
    printf("Freeing list\n");
    d = free_list(d);
    print_list(d);
    return 0;
}