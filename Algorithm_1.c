/* *****************************************************************
 *  Algorithm_1.c
 *
 *  Author: Ahmed Nofal, Instructor at Sprints LLC.
 ******************************************************************/

/******************************************************************
 * Given an array of integers, return indices of
 * the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 ***********
 * example *
 ***********
 * 		input: [10,2,23,4,5], target = 6
 * 		output: [1,3]
 *
 * *****************************************************************/
 #include "Algorithm_1.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
		/* Your code goes here */
		static int result[2] = {0, 0};
		int* result_pointer = &result[0];
		int break_from_bigger_loop_flag = 0;
		for(int i = 0; i < numsSize; i++){
            if (nums[i] >= target){

            }
            else{
                for (int j = (i + 1); j < numsSize; j++){
                    if ((nums[i] + nums[j]) == target){
                        result[0] = i;
                        result[1] = j;
                        break_from_bigger_loop_flag = 1;
                        break;
                    }
                }
            }
            if (break_from_bigger_loop_flag == 1){
                break;
            }
		}
		return result_pointer;
}
