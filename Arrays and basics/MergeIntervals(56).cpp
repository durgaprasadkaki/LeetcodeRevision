/*
56. Merge Intervals
Solved
Medium
Topics
premium lock icon
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
 and return an array of the non-overlapping intervals that cover all the intervals in the input.
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
    
       int n=intervals.size();
       sort(intervals.begin(), intervals.end());
       int left=intervals[0][0];
       int right=intervals[0][1];
       for(int i=1; i<n; i++){
              if(intervals[i][0]>right){
                ans.push_back({left, right});
                left=intervals[i][0];
                right=intervals[i][1];
              }
              right=max(right, intervals[i][1]);
       }
       ans.push_back({left, right});
       return ans;
    }
};