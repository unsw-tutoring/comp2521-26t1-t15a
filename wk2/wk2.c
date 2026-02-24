#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(char *string) {
    // compare 'mirrored' letters

    // int i, j -> i points to the start; j to the end
    for (int i = 0, j = strlen(string) - 1; i < j;
         i++, j--) {  // runs O(n) times
        if (string[i] != string[j]) {
            return false;
        }
    }
    // if any of them are different (string[i] != string[j]) -> return false

    return true;
}

// arr = [3,4,5]; target = 7 => true
// arr = [3,4,5]; target = 10 => false
bool twoSum(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {          // O(n)
        for (int j = i + 1; j < size; j++) {  // O(n)
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }

    return false;
}

// to find n!
//  find (n-1)!
//  multiply the result by n
//
// base case: 0! == 1

// move n disks from A to C, using B as an extra rod:
//  move n-1 disks from A to B, using C as an extra rod
//  move nth disk from A to C
//  move n-1 disks from B to C, using A as an extra rod
//
// base case: if I'm told to move 0 disks, then do nothing

// a linked list is either:
// - a node with a pointer to a linked list
// - empty (NULL)

int listLength(struct node *l) {
    if (l == NULL) return 0;
    return 1 + listLength(l->next);
}

int listCountOdds(struct node *l) {
    if (l == NULL) return 0;

    int countOfOddNumbersInRestOfList = listCountOdds(l->next);
    if (l->value % 2 == 1) {
        return countOfOddNumbersInRestOfList + 1;
    }
    return countOfOddNumbersInRestOfList;
}

bool listIsSorted(struct node *l) {
    if (l == NULL) return true;
    if (l->next == NULL) return true;
    return (l->value <= l->next->value) && listIsSorted(l->next);
}

struct node *listDelete(struct node *l, int value) {
    if (l == NULL) return NULL;
    if (l->value == value) {
        struct node *newHead = l->next;
        free(l);
        return newHead;
    }

    l->next = listDelete(l->next, value);
    return l;
}

/**
 * Helper function
 */
struct node {
    int value;
    struct node *next;
};
struct list {
    struct node *head;
};

int dolistLength(struct node *l) {
    if (l == NULL) return 0;
    return 1 + dolistLength(l->next);
}
int listLength(struct list *l) {
    return doLength(l->head);
}