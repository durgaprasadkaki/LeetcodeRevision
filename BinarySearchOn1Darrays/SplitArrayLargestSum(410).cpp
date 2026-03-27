/*
410. Split Array Largest Sum
Solved
Hard
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum
 of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid){
        int sum = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                count++;
                sum = nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(isPossible(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};