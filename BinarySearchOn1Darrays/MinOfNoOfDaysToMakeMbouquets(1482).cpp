/*
1482. Minimum Number of Days to Make m Bouquets
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one
 bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is
 impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not 
bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int mid,int m,int k){
        int count=0; int bouquet=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                bouquet+=count/k;
                count=0;
            }
        }
        bouquet+=count/k;
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m*k>n) return -1;
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        while(left<right){
            int mid=(left+right)/2;
            if(isPossible(bloomDay,mid,m,k)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};