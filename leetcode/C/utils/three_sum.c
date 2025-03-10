#include <stdio.h>
#include <stdlib.h>
#include "../include/three_sum.h"

/*
LeetCode Problem : Three Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
*/


int* three_sum(int* nums){
    int* result = (int*)malloc(3*sizeof(int));
    int n = sizeof(nums)/sizeof(nums[0]);
    int i, j, k;
    for(i=0; i<n-2; i++){
        for(j=i+1; j<n-1; j++){
            for(k=j+1; k<n; k++){
                if(nums[i]+nums[j]+nums[k] == 0){
                    result[0] = nums[i];
                    result[1] = nums[j];
                    result[2] = nums[k];
                    return result;
                }
            }
        }
    }
    return NULL;
}