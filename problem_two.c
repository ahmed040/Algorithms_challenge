/*********************************************************************************
 *
 *  problem_two.c
 *  Author: Ahmed Nofal, Instructor at Sprints LLC
 *
 ********************************************************************************/


/****************************[Problem Description]*********************************
 *
 * Modify the Binary Search algorithm to find an element in a circularly sorted
 * array.
 * The array is sorted in an ascending order and rotated in clockwise
 *
 * Sample Input: arr = [8, 9, 10, 2, 5, 6]
 * 				 target = 10
 * Sample Output: The number is found at index 2
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_two.h"

/*********************************************************************************
 *
 * Function: circularArraySearch
 *
 * @param: arr[], Array that the function should find the number in.
 * @param: arr_size, Size of the array
 * @param: element_to_be_found, The elment to be searcher for
 * @return: int, the index of the element to be found
 *
 * Description: Function to find the number of times the array is rotated, if the
 * element was not found it should return -1
 *
 ********************************************************************************/
 #include "problem_two.h"
int circularArraySearch(int arr[], int arr_size, int element_to_be_found)
{
	/* Your code goes here */
	//I am trying at the start to find the index of the smallest number using binary search
	int min = 0;
	int max = arr_size - 1;
	int middle = (min + max) / 2;
	int i = middle;
	int sorted_from_begining_flag = 0;
	// special cases
	if(element_to_be_found == arr[arr_size - 1]){
        return (arr_size - 1);
	}
	else if (element_to_be_found == arr[0]){
        return 0;
	}
    //now the code
	while((arr[i]) <= arr[i + 1]){
            if (arr[arr_size - 1] > arr[0]){
                i = 0;
                sorted_from_begining_flag = 1;
                break;
            }
            if (arr[i] <= arr[0]){
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
    if (sorted_from_begining_flag == 0){
        i = i + 1;
    }
    /*
    found the smallest number index, now I divide the array
    into two intervals and do binary search in the right interval
    */
    // new special cases
    int absolute_max = arr[i - 1];
    int absolute_min = arr[i];
    if (element_to_be_found > absolute_max){
        return - 1;
    }
    else if (element_to_be_found < absolute_min){
        return - 1;
    }
    if(element_to_be_found == arr[i - 1]){
        return (i - 1);
	}
	else if (element_to_be_found == arr[i]){
        return i;
	}
    if (element_to_be_found < arr[arr_size - 1]){
        min = i;
        max = arr_size - 1;
    }
    else if (element_to_be_found > arr[0]){
        min = 0;
        max = i - 1;
    }
    middle = (min + max) / 2;
    i = middle;

    while (arr[middle] != element_to_be_found){
        if (element_to_be_found < arr[middle]){
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
	return i;
}

/* circularArraySearch_test */
void circularArraySearch_test(void)
{
	int A[] = {9, 10, 2, 5, 6, 8};
	int target = 10;
	int n = sizeof(A)/sizeof(A[0]);
	int index = circularArraySearch(A, n, target);
	if(index != -1){
		printf("Element found at index %d", index);
	}
	else{
		printf("Element not found in the array");
	}

}
