/** 
 * Created By: Donald Gaeta
 * Date: 1/30/24 @ 9:17PM
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
 * Date: 1/30/24
 * Effort: 1 hr
 * Purpose: Practice using bitwise operators and shifts to manipulate flags within an integer.
 ***********************************************************/ 

#include <stdio.h>


/**
 * Function prototypes
 */
void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

/**
 * Set the bit at flag_position to a 1 by shifting 1 over by flag_position
 */
void set_flag(unsigned int* flag_holder, int flag_position) {
    *flag_holder |= 1 << flag_position;
}

/**
 * Unset the bit at flag_position to a 0 by inverting all bits and shifting,
 * then anding it with the flag holder.
 */
void unset_flag(unsigned int* flag_holder, int flag_position) {
    *flag_holder &= ~(1 << flag_position);
}

/**
 * Check if the bit at flag_position is 1
 */
int check_flag(unsigned int flag_holder, int flag_position) {
    return (flag_holder >> flag_position) & 1;
}

/**
 * Display the 32 flags of the flag holder
 */
void display_32_flags(unsigned int flag_holder) {
    int i;
    for(i = 31; i >= 0; i--) {
        printf("%d", check_flag(flag_holder, i));
        if(i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    unsigned int flag_holder = 0; 

    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);

    display_32_flags(flag_holder);

    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);

    display_32_flags(flag_holder);
    return 0; 
}
