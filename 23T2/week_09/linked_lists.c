// Program to do various linked list exercises
// Written by Angella Pham (z5361210)

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;		// data item at this node
	struct node *next;		// pointer to the next node
};

/** PRESCRIBED FUNCTIONS **/

// Append to a linked list
struct node *add_last(struct node *head, int data);

// Prints the data of a linked list
void print_list(struct node *head);

struct node *free_list(struct node *list);

// Returns a copy of the linked list and frees the original list.
struct node *copy(struct node *head);

// Returns a new linked list where it is the second appended to the first
struct node *list_append(struct node *first_list, struct node *second_list);

int main(void) {

    // Testing copy()

    // 1 -> 2 -> 3 -> 4 -> 5 -> X
    struct node *list_A = NULL;
    list_A = add_last(list_A, 1);
    list_A = add_last(list_A, 2);
    list_A = add_last(list_A, 3);
    list_A = add_last(list_A, 4);
    list_A = add_last(list_A, 5);

    struct node *list_B = copy(list_A);
    print_list(list_B);

    // Testing list_append()

    // 1 -> 2 -> 3 -> 4 -> 5 -> X
    struct node *list_C = NULL;
    list_C = add_last(list_C, 1);
    list_C = add_last(list_C, 2);
    list_C = add_last(list_C, 3);
    list_C = add_last(list_C, 4);
    list_C = add_last(list_C, 5);

    // 6 -> 7 -> 8 -> 9 -> 10 -> X
    struct node *list_D = NULL;
    list_D = add_last(list_D, 6);
    list_D = add_last(list_D, 7);
    list_D = add_last(list_D, 8);
    list_D = add_last(list_D, 9);
    list_D = add_last(list_D, 10);

    struct node *list_E = list_append(list_C, list_D);
    print_list(list_E);
    
    return 0;
}

/** PRESCRIBED FUNCTIONS **/

struct node *add_last(struct node *head, int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // Return new if linked list is initially empty
    if (head == NULL) {
        return new;
    }

    // Otherwise, loop to end of list and add node.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    // We are inserting at the end --> head will not change
    return head;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

struct node *free_list(struct node *list) {
    while (list != NULL) {
        struct node *prev = list;
        list = list->next;
        free(prev);
    }
    return NULL;
}

struct node *copy(struct node *list) {
    struct node *new_list = NULL;

    struct node *curr = list;
    while (curr != NULL) {
        new_list = add_last(new_list, curr->data);
        curr = curr->next;
    }

    free_list(list);

    return new_list;
}

struct node *list_append(struct node *first_list, struct node *second_list) {
    
    if (first_list == NULL) {
        return second_list;
    }

    struct node *curr = first_list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = second_list;

    return first_list;
}