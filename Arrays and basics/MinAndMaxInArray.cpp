/*
100. Minimum and Maximum in an Array
Solved
Easy
Topics
Companies
Given an integer array nums, return the minimum and maximum values in the array.
Example 1:
Input: nums = [3,2,1]
Output: [1,3]
Example 2:
Input: nums = [1,2,3,4]
Output: [1,4]
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minMax(vector<int>& nums) {
        int min=INT_MAX;
        int max=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<min){
                min=nums[i];
            }
            if(nums[i]>max){
                max=nums[i];
            }
        }
        return {min,max};
    }
};