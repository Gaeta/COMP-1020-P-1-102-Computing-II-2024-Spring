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

/***********************************************************
 * Author: Donald Gaeta
 * Date: 2/17/24
 * Effort: 3 hr
 * Purpose: Declarations for stack operations used in checking the correctness of strings containing parentheses, brackets, and braces.
 ***********************************************************/

#include <stdio.h>
#include <string.h>
#include "stack.c"

int isCorrectString(char* str) {
    Node* stack = NULL;
    
    // Loop through the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Use switch chase
        switch (str[i]) {
            // if C [ {, push it onto the stack
            case '(': case '{': case '[':
                push(&stack, str[i]);
                break;
            // if C ] }, pop from the stack and check if it matches
            case ')': case '}': case ']':
                if (isEmpty(stack)) return 0;
                char c = pop(&stack);
                if (c == '(' && str[i] != ')') return 0;
                if (c == '{' && str[i] != '}') return 0;
                if (c == '[' && str[i] != ']') return 0;
                break;
            default:
                break;
        }
    }

    // If the stack is empty, return 1, else return 0, and clean up the stack

    int result = isEmpty(stack);
    while (!isEmpty(stack)) {
        pop(&stack);
    }
    return result;
}

int main() {

    printf("Enter the number of strings: ");
    int n; // # of strings
    scanf("%d", &n);

    char str[1001]; // Max string length chars

    printf("Enter the strings: \n");

    for (int i = 0; i < n; i++) {
        // Read string
        scanf("%s", str);
        printf("Print: %s\n", str);

        printf("Status: ");
        if (isCorrectString(str)) {
            printf("Correct\n");
        } else {
            printf("Incorrect\n");
        }

        // Print string
    }

}