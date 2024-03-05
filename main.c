/** 
 * Created By: Donald Gaeta
 * Date: 2/23/24 @ 2:50pm
 * 
 * 
 * Copyright (c) 2024 Donald J Gaeta (Gaeta.me)
 * This software is provided "as is" for educational and grading purposes only by authorized individuals. 
 * Any use, reproduction, distribution, or modification of this software for purposes other than those 
 * mentioned is strictly prohibited. Unauthorized use may result in legal action. All rights reserved. 
 * The author retains perpetual ownership of this software and its associated materials.
*/

/** 
 * Task:
 * 
 * How can you take a linked list and reverse it?
 * This is a classic data structures question for interview candidates and so I want you to give it a try.  
 * Take the given starter code listed with this assignment and add in the code needed to reverse the linked list.  
 * Your algorithm should complete in linear time and should not require you to build a second list.
 * 
*/
/***********************************************************
 * Author: Donald Gaeta
 * Date: 2/23/24
 * Effort: 2 hr
 * Purpose: Practice add two numbers represented as linked lists.
 ***********************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

// SUCCESS or failure of the function :D
typedef enum { FAILURE, SUCCESS } Result;

//declare your function here.
int head_insert(Node** head, int digit);
void print_list(Node* head);
void destroy_list(Node** head);
int reverseList(Node** head);
Node* list_sum(Node* head1, Node* head2);


// Pre provided code from the assignment
int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head_sum = NULL;

    head_insert(&head1, 9);
    head_insert(&head1, 8);
    head_insert(&head1, 1);

    head_insert(&head2, 1);
    head_insert(&head2, 1);


    // Add the two numbers
    head_sum = list_sum(head1, head2);

    // Print the sum of the two numbers
    printf("The sum of ");
    print_list(head1);
    printf(" + ");
    print_list(head2);
    printf(" = ");
    print_list(head_sum);
    printf("\n");

    // Cleanup
    destroy_list(&head1);
    destroy_list(&head2);
    destroy_list(&head_sum);

    return 0;
}

// Implement the head_insert function
int head_insert(Node** head, int digit) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return -1; // Memory allocation failed
    }
    new_node->data = digit;
    new_node->next = *head;
    *head = new_node;
    return SUCCESS;
}

// Implement the print_list function
void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
}

// Implement the destroy_list function
void destroy_list(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

//Define your function here
int reverseList(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return SUCCESS;
}

Node* list_sum(Node* head1, Node* head2) {
    // reverseList(&head1);
    // reverseList(&head2);

    Node* sum_head = NULL;
    int head1_sum = 0;
    int head2_sum = 0;
    int total_sum = 0;

    while (head1 != NULL)
    {
        head1_sum = head1_sum * 10 + head1->data;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        head2_sum = head2_sum * 10 + head2->data;
        head2 = head2->next;
    }

    total_sum = head1_sum + head2_sum;

    while (total_sum > 0)
    {
        head_insert(&sum_head, total_sum % 10);
        total_sum = total_sum / 10;
    }

    return sum_head;
}