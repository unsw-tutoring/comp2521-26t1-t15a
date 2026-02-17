#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

// return the number of nodes in a linked list, given its head
int listLength(struct node *list);

// use a for loop
int listLength(struct node *list) {
    int length = 0;
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        length += 1;
    }
    return length;
}
