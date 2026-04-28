/*
539. Minimum Time Difference
Solved
Medium
Topics
premium lock icon
Companies
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference
 between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findMinDifference(vector<string> &timePoints) {
        vector<int> minutes;
        for (const string &time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (size_t i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        // Check the difference between the last and first time points
        minDiff = min(minDiff, 1440 - (minutes.back() - minutes.front()));
        return minDiff;
    }
};