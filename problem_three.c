/*********************************************************************************
 *
 *  problem_three.c
 *  Author: Ahmed Nofal, Instructor at Sprints LLC
 *
 ********************************************************************************/

/****************************[Problem Description]*********************************
 *
 * Count occurances of a number in a sorted array
 * Sample Input: arr= [2,2, 4, 5, 5, 5, 5, 6, 6]
 * 				 target = 5
 * Sample Output: The number 5 occured 4 times in the array
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_three.h"

/*********************************************************************************
 *
 * Function: BinarySearchOccurances
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: target, The elment to be searched for the last occurance for
 * @param: searchFirst, Indicates whether you are using this function to get the
 * first occurance of the target or last (1 for first and 0 for last)
 * @return: int, the index of the last occurance of the element
 *
 * Description: function to get the number of occurances of a target element in a
 * given sorted array.
 *
 *
 ********************************************************************************/
int BinarySearchOccurances(int arr[], int arr_size, int target, int searchFirst){
	/* Your code goes here */
	int min = 0;
	int max = arr_size - 1;
	int middle = (min + max) / 2;
	int i = middle;
    //finding a middle instance
    // handling special cases
    if (target > arr[max]){
        return - 1;
    }
    else if (target < arr[min]){
        return - 1;
    }
    while (arr[middle] != target){
        printf("%d, \n", 1);
        if (target < arr[middle]){
            max = middle;
            middle = min + ((max - min) / 2);
            i = middle;
        }
        else {
            min = middle;
            middle = min + ((max - min) / 2);
            i = middle;
        }
    }
    //now finding first or last
    if (searchFirst == 1){

        min = 0;
        max = i;
        middle = i/2;
        while(1){
            if(arr[middle] != target){
                if (arr[middle + 1] == target){
                    return (middle + 1);
                }
                min = middle;
                middle = min + ((max - min) / 2);
            }
            else if (arr[middle] == target){
                if (arr[middle - 1] != target){
                    return (middle);
                }
                max = middle;
                middle = min + ((max - min) / 2);
            }

        }

    }
    else if (searchFirst == 0){
        if (arr[arr_size - 1] == target){
            return (arr_size - 1);
        }
        min = i;
        max = arr_size - 1;
        middle = min + ((max - min) / 2);
        while(1){
            if(arr[middle] != target){
                if (arr[middle - 1] == target){
                    return (middle - 1);
                }
                max = middle;
                middle = min + ((max - min) / 2);
            }
            else if (arr[middle] == target){
                if (arr[middle + 1] != target){
                    return (middle);
                }
                min = middle;
                middle = min + ((max - min) / 2);
            }

        }

    }
}

/* Count occurrences of a number in a sorted array with duplicates*/
void BinarySearchOccurances_test(void)
{
	int A[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
	int target = 5;

	int n = sizeof(A)/sizeof(A[0]);
	int first = BinarySearchOccurances(A, n, target, 1);  // 1 for first occurrence
	int last = BinarySearchOccurances(A, n, target, 0);   // 0 for last occurrence

	int count = last - first + 1;

	if (first != -1)
		printf("Element %d occurs %d times.", target, count);
	else
		printf("Element not found in the array.");
}

