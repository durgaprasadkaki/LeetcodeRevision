/*2733. Neither Minimum nor Maximum
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an integer array nums containing distinct positive integers, find and return any number
 from the array that is neither the minimum nor the maximum value in the array, or -1 if there is no such number.
Return the selected integer.
Example 1:

Input: nums = [3,2,1,4]
Output: 2
Explanation: In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.
Example 2:

Input: nums = [1,2]
Output: -1
Explanation: Since there is no number in nums that is neither the maximum nor the minimum, we cannot select a
 number that satisfies the given condition. Therefore, there is no answer.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int min=INT_MAX;
        int max= INT_MIN;
       if(n<=2){
        return -1;
       }
       for(int i=0; i<n; i++){
        if(nums[i]<min){
            min=nums[i];
        }
        else if(nums[i]>max){
            max=nums[i];
        }
       }
       for(int i=0; i<n; i++){
        if(nums[i]!=min && nums[i]!=max){
            return nums[i];
        }
       }
       return -1;
    }
};