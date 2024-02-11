/** 
 * Created By: Donald Gaeta
 * Date: 2/05/24 @ 5:00PM
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
 * Date: 2/05/24
 * Effort: 1 1/2 hr
 * Purpose: Practice using bitwise operators and shifts to manipulate flags within an integer arrays.
 ***********************************************************/ 

#include <stdio.h>

/**
 * Function prototypes
 */
void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

/**
 * Set the bit at flag_position to a 1 by shifting 1 over by flag_position
 */
void set_flag(unsigned int flag_holder[], int flag_position) {
    int index = flag_position / 32; // Find the index of the integer in the array
    int bit_position = flag_position % 32; // Find the position within the integer
    flag_holder[index] |= 1 << bit_position;
}

/**
 * Unset the bit at flag_position to a 0 by inverting all bits and shifting,
 * then anding it with the flag holder.
 */
void unset_flag(unsigned int flag_holder[], int flag_position) {
    int index = flag_position / 32;
    int bit_position = flag_position % 32;
    flag_holder[index] &= ~(1 << bit_position);
}

/**
 * Check if the bit at flag_position is 1
 */
int check_flag(unsigned int flag_holder[], int flag_position) {
    int index = flag_position / 32;
    int bit_position = flag_position % 32;
    return (flag_holder[index] >> bit_position) & 1;
}

/**
 * Display the flags of the flag holder as an array
 */
void display_flags_as_array(unsigned int flag_holder) {
    for (int i = 0; i < 32; i++) {
        printf("%d", (flag_holder >> i) & 1);
        if ((i + 1) % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

/**
 * Display the flags one integer per line
 */
void display_flags(unsigned int flag_holder[], int size) {
    for (int i = 0; i < size; i++) {
        display_flags_as_array(flag_holder[i]);
    }
}

int main(int argc, char* argv[]) {
    unsigned int flag_holder[5] = {0}; // Set the first integer to zero and all others to zero by default.

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);

    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);

    display_flags(flag_holder, 5);
    return 0;
}
