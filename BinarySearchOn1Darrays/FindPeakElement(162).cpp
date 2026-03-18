/*
162. Find Peak Element
Solved
Medium
Topics
premium lock icon
Companies
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains 
multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly 
greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or
 index number 5 where the peak element is 6.
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int left=1; int right=n-2;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
};

/* it is also optimal solution with less code and less time complexity than above code
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =nums.size();
        int left=0;
        int right=n-1;
        
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]<nums[mid+1]){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
    }
};*/