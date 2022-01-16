/*
 * Created by gt on 11/24/21 - 8:09 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

struct ll_node {
    char data;
    struct ll_node *pNext;
};

void insert(struct ll_node **head, char value);
void insert_at_end(struct ll_node **head, char value);
void insert_at_beginning(struct ll_node **head, char value);
char delete(struct ll_node **head, char value);
void delete_at_beginning(struct ll_node **head);
int is_empty(struct ll_node *head);
void print_list(struct ll_node *current_ptr);
void display_menu();

int main() {
    struct ll_node *head = NULL;  // initially there are no nodes
    int choice = -1;
    char item;

    while (choice) {
        display_menu();
        printf(":: ");
        scanf("%i", &choice);

        switch (choice) {
            case 0:
                printf("End of run.\n");
                return 0;
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&head, item);
                print_list(head);
                break;

            case 2:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert_at_end(&head, item);
                print_list(head);
                break;

            case 3:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert_at_beginning(&head, item);
                print_list(head);
                break;

            case 4:
                if (!is_empty(head)) {
                    printf("Enter a character: ");
                    scanf("\n%c", &item);
                    if (delete(&head, item)) {
                        printf("%c deleted.\n", item);
                    } else {
                        printf("%c is not found.\n\n", item);
                    }
                }
                break;

            case 5:
                if (!is_empty(head)) {
                    char will_delete = head->data;
                    delete_at_beginning(&head);
                    printf("%c is deleted\n", will_delete);
                } else {
                    printf("List is empty.\n\n");
                }
                break;

            case 6:
                print_list(head);
                break;

            default:
                printf("Invalid choice.\n\n");
                display_menu();
                break;
        }
    }
}

// insert in alphabetical order
void insert(struct ll_node **head, char value) {
    struct ll_node *new_ptr = malloc(sizeof (struct ll_node));
    struct ll_node *prev_ptr;
    struct ll_node *cur_ptr;

    if (new_ptr != NULL) {
        new_ptr->data = value;
        new_ptr->pNext = NULL;

        prev_ptr = NULL;
        cur_ptr = *head;

        while (cur_ptr != NULL && value > cur_ptr->data) {
            prev_ptr = cur_ptr;
            cur_ptr = cur_ptr->pNext;
        }

        if (prev_ptr == NULL) {
            new_ptr->pNext = *head;
            *head = new_ptr;
        } else {
            prev_ptr->pNext = new_ptr;
            new_ptr->pNext = cur_ptr;
        }
    } else {
        printf("%c is not inserted. No memory available.\n", value);
    }
}

void insert_at_end(struct ll_node **head, char value) {
    struct ll_node *current = *head;
    if (current != NULL) {
        while (current->pNext != NULL) {
            current = current->pNext;
        }

        current->pNext = malloc(sizeof (struct ll_node));
        current->pNext->data = value;
        current->pNext->pNext = NULL;
    } else {
        current = malloc(sizeof (struct ll_node));
        current->data = value;
        current->pNext = NULL;
        *head = current;
    }
}

void insert_at_beginning(struct ll_node **head, char value) {
    struct ll_node *new_ll_node = malloc(sizeof (struct ll_node));
    new_ll_node->data = value;
    new_ll_node->pNext = *head;
    *head = new_ll_node;
}

char delete(struct ll_node **head, char value) {
    struct ll_node *prev_ptr;
    struct ll_node *cur_ptr;
    struct ll_node *tmp_ptr;

    if (value == (*head)->data) {
        tmp_ptr = *head;
        *head = (*head)->pNext;
        free(tmp_ptr);
    } else {
        prev_ptr = *head;
        cur_ptr = (*head)->pNext;

        while (cur_ptr != NULL && cur_ptr->data != value) {
            prev_ptr = cur_ptr;
            cur_ptr = cur_ptr->pNext;
        }

        if (cur_ptr != NULL) {
            tmp_ptr =cur_ptr;
            prev_ptr->pNext = cur_ptr->pNext;
            free(tmp_ptr);
            return value;
        }
    }
    return '\0';
}

void delete_at_beginning(struct ll_node **head) {
    struct ll_node *tmp_ptr = NULL;
    if (head == NULL) {
        return;
    } else {
        tmp_ptr = *head;
        *head = (*head)->pNext;
        free(tmp_ptr);
    }
}

int is_empty(struct ll_node *head) {
    return head == NULL;
}

void print_list(struct ll_node *current_ptr) {
    if (current_ptr == NULL) {
        printf("List is empty.\n\n");
    } else {
        printf("The list is: \n");
        while (current_ptr != NULL) {
            printf("%c --> ", current_ptr->data);
            current_ptr = current_ptr->pNext;
        }

        printf("NULL\n\n");
    }
}

void display_menu() {
    printf("Enter your choice:\n"
           "0 to quit.\n"
           "1 to insert an element into the list in alphabetical order\n"
           "2 to insert an element at the end of the list.\n"
           "3 to insert an element at the beginning of the list.\n"
           "4 to delete an element from the list.\n"
           "5 to delete an element from the beginning of the list.\n"
           "6 to print list.\n"
    );
}