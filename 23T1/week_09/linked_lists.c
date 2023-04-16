// Emily Chen & Tom Kunc
// Program to do various linked list exercises
// Written by <your-name> (zID) on <date>

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

// Returns a copy of the linked list and frees the original list.
struct node *copy(struct node *head);

// Returns a new linked list where it is the second appended to the first
struct node *list_append(struct node *first_list, struct node *second_list);

int main(void) {

    // Testing copy()

    struct node *list_A = NULL;
    list_A = add_last(list_A, 1);
    list_A = add_last(list_A, 2);
    list_A = add_last(list_A, 3);
    list_A = add_last(list_A, 4);
    list_A = add_last(list_A, 5);

    struct node *list_B = copy(list_A);
    print_list(list_B);

    // Testing list_append()

    struct node *list_D = NULL;
    list_D = add_last(list_D, 1);
    list_D = add_last(list_D, 2);
    list_D = add_last(list_D, 3);
    list_D = add_last(list_D, 4);
    list_D = add_last(list_D, 5);

    struct node *list_E = NULL;
    list_E = add_last(list_E, 6);
    list_E = add_last(list_E, 7);
    list_E = add_last(list_E, 8);
    list_E = add_last(list_E, 9);
    list_E = add_last(list_E, 10);

    struct node *list_F = list_append(list_D, list_E);
    print_list(list_F);
    
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

struct node *copy(struct node *list) {
    
    struct node *new_list = NULL;

    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        new_list = add_last(new_list, curr->data);
    }

    struct node *next = NULL;
    for (struct node *curr = list; curr != NULL; curr = next) {
        next = curr->next;
        free(curr);
    }

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