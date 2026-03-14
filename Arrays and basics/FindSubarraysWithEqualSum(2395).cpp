/*
2395. Find Subarrays With Equal Sum
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

Return true if these subarrays exist, and false otherwise.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
Example 2:

Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;

        for(int i = 0; i < nums.size() - 1; i++){
            int sum = nums[i] + nums[i+1];
            if(st.count(sum)) {
                return true;
            }
            st.insert(sum);
        }
        return false;   
    }
};
/*
int n=nums.size();
        for(int i=0; i<n-1; i++){
            int sum1=nums[i]+nums[i+1];
            for(int j=i+1; j<n-1; j++){
               int sum2=nums[j]+nums[j+1];
            
            
            if(sum1==sum2){
                return true;
            }
        }
        }
        return false;
        */