/*
Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        int maxi =0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==0){
                maxi=i+1;
            }
            else{
                if(mpp.find(sum)!=mpp.end()){
                    maxi=max(maxi, i-mpp[sum]);
                }
                else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
};