/*
453. Minimum Moves to Equal Array Elements
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.

 

Example 1:

Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Example 2:

Input: nums = [1,1,1]
Output: 0*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int minValue = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minValue) {
                minValue = nums[i];
            }
        }

        int moves = 0;

        for (int i = 0; i < nums.size(); i++) {
            moves = moves + (nums[i] - minValue);
        }

        return moves;
    }
};