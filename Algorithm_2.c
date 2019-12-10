/* *****************************************************************
 *  Algorithm_2.c
 *
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/
#include <stdio.h>

/*********************************************************************************
*	Given a number n, write a program to print a diamond shape with 2n rows.
*
*	Input: 5
*	Output:
*				*
*			   * *
*			  * * *
*			 * * * *
*			* * * * *
*			* * * * *
*			 * * * *
*			  * * *
*			   * *
*				*
********************************************************************************/
#include "Algorithm_2.h"
#include <string.h>

void PrintDiamond(int n)
{
	/* Your code goes here  */
	char space_only[2] = {' ', '\0'};
	char star_and_space[3] = {'*', ' ', '\0'};
	for (int i = 1; i <= n; i++){
        for (int j = 0; j < n; j++){
            if(j <= (n - i - 1)){
                printf("%s", space_only);
            }
            else{
                printf("%s", star_and_space);
            }
        }
        printf("\n");
	}
	for (int i = 0; i < n; i++){
        printf("%s", star_and_space);
	}
	printf("\n");
	for (int i = 0; i <= n-1; i++){
        for (int j = n - 1; j >= 0; j--){
            if(j >= (n - i - 1)){
                printf("%s", space_only);
            }
            else{
                printf("%s", star_and_space);
            }
        }
        printf("\n");
	}
}


