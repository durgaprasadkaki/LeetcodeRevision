/*
Count Subarrays with given XOR
Difficulty: MediumAccuracy: 58.86%Submissions: 86K+Points: 4
Given an array of integers arr[] and a number k, count the number
 of subarrays having XOR of their elements as k.

Note: It is guranteed that the total count will fit within a 
32-bit integer.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 
6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the 
answer is 4.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
       map<int, int> mpp;
       int xr=0;
       mpp[xr]++; //(0, 1)
       int cnt = 0;
       for(int i=0; i<arr.size(); i++){
           xr=xr^arr[i];
           int x=xr^k;
           cnt+=mpp[x];
           mpp[xr]++;
       }
       return cnt;
    }
};
/*
 int n = arr.size();
        long count = 0;

        for(int i = 0; i < n; i++){
            int xr = 0;

            for(int j = i; j < n; j++){
                xr = xr ^ arr[j];

                if(xr == k){
                    count++;
                }
            }
        }
        return count;*/