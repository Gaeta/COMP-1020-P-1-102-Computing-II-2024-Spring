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
 * Purpose: To create a program that sets and checks flags
 ***********************************************************/ 


/** 
 * Default Libraries
*/
#include <stdio.h> 

/** 
 * Function prototypes
*/
void set_flag(int* pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

void set_flag(int* pFlag_holder, int flag_position) {
    /** 
     * Set the bit at flag_position
     * to a 1 by shifting 1 over by flag_position
    */
    *pFlag_holder |= 1 << flag_position;
}

int check_flag(int flag_holder, int flag_position) {
    /** 
     * Check if the bit at flag_position
     * is 1
    */
    return (flag_holder >> flag_position) & 1;
}

int main(int argc, char* argv[]) { 
    int flag_holder = 0; 
    int i; 

    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);


    for(i = 31; i >= 0; i--) { 
        printf("%d", check_flag(flag_holder, i));
        if(i % 4 == 0) { 
            printf(" ");
        }
    }
    printf("\n");
    return 0; 
}
