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

#ifndef STACK_H
#define STACK_H

// Node definition for a character stack
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Stack operations
void push(Node** top, char data);
char pop(Node** top);
int isEmpty(Node* top);

#endif // STACK_H