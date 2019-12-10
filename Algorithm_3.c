/* *****************************************************************
 *  Algorithm_3.c
 *
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/

/*********************************************************************************
*	Given a number, print floor of 5’th root of the number.
*
*	Input  : n = 32
*	Output : 2
*	2 raise to power 5 is 32
*
*	Input  : n = 250
*	Output : 3
*	Fifth square root of 250 is between 3 and 4
*	So floor value is 3.
********************************************************************************/
#include "Algorithm_3.h"
 // I will implement binary search here as well
int Linear_floorRoot5(int n)
{
	/* Your code goes here  */
	int min = 1;
	int max = 74;
	int middle = 37;
	int sign = 1;
	if (n == 0){
        return 0;
	}
	else if (n < 0){
        n = (-1) * n;
        sign = -1;
	}
	if (n == 1){
        return 1;
	}
	else{
        while((max - min) > 1){
            if ((n) < (middle * middle * middle * middle * middle)){
                max = middle;
                middle = min + ((max - min) / 2);
            }
            else {
                min = middle;
                middle = min + ((max - min) / 2);
            }
        }
	}
	return sign * min;
}

