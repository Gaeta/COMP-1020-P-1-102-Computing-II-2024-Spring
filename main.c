/** 
 * Created By: Donald Gaeta
 * Date: 1/24/24 @ 9:46PM
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
  * Date: 1/24/24  
  * Effort: 1.5 hour  
  * Purpose: Practice with left shift operators
  ***********************************************************/ 

#include <stdio.h>

int main (int argc, char* argv[]) {
   int a = 1;
   for (int i = (sizeof(int) * 8); i >= 1; i--) {
      printf("%u\n", a);
      a = a << 1;
   }

   return 0;
}

//  :D :D
// >:X