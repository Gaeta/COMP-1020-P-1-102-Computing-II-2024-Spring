/** 
 * Created By: Donald Gaeta
 * Date: 1/21/24 @ 7:17PM
 * 
 * 
 * Copyright (c) 2024 Donald J Gaeta (Gaeta.me)
 * This software is provided "as is" for educational and grading purposes only by authorized individuals. 
 * Any use, reproduction, distribution, or modification of this software for purposes other than those 
 * mentioned is strictly prohibited. Unauthorized use may result in legal action. All rights reserved. 
 * The author retains perpetual ownership of this software and its associated materials.
*/

/** 
 * Default C Libs
*/
#include <stdio.h>

/** 
 * Function Prototype
*/
char* reverse(char* str);

/** 
 * Main Program given by Prof 
*/
int main(int argc, char* argv[])
{
    char word[] = "Happy Birthday!";
    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    printf("%s\n", reverse(word));
    printf("%s\n", word);
    return 0;
} 

/** 
 * Reverse function
 * 
 * Use: Provide String, outputs with reverse string.
*/
char* reverse(char* str) {

    // Calculate the length of the string, since no other lib can be used
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    return str;
}
