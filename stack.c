/** 
 * Created By: Donald Gaeta
 * Date: 2/17/24 @ 8:30PM
 * 
 * 
 * Copyright (c) 2024 Donald J Gaeta (Gaeta.me)
 * This software is provided "as is" for educational and grading purposes only by authorized individuals. 
 * Any use, reproduction, distribution, or modification of this software for purposes other than those 
 * mentioned is strictly prohibited. Unauthorized use may result in legal action. All rights reserved. 
 * The author retains perpetual ownership of this software and its associated materials.
*/

#include <stdlib.h>
#include "stack.h"

// Push a character onto the stack
void push(Node** top, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Pop a character from the stack
char pop(Node** top) {
    if (*top == NULL) return '\0';
    Node* temp = *top;
    char data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}
