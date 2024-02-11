/** 
 * Created By: Donald Gaeta
 * Date: 2/08/24 @ 8:30PM
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
 * Date: 2/08/24
 * Effort: 1 hr
 * Purpose: Practice reversing string using pointers
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

// SUCCESS or failure of the function
typedef enum { FAILURE, SUCCESS } Result;

//declare your function here.
int reverseList(Node** head);


int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

    printf("***\nOriginal List\n");
    // Check list before hand
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("***\n");

	//call your function and then print the list.
    if (reverseList(&head) == FAILURE)
    {
        printf("Failed to reverse list\n");
        return 1;
    }

    printf("***\nReversed List\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("***\n");

    return 0;
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