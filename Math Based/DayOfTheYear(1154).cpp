/*
1154. Day of the Year
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, 
return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            days[1] = 29;
        }
        
        int total = 0;
        
        for (int i = 0; i < month - 1; i++) {
            total += days[i];
        }
        
        total += day;
        
        return total;
    }
};