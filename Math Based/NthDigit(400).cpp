/*
400. Nth Digit
Solved
Medium
Topics
premium lock icon
Companies
Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

 

Example 1:

Input: n = 3
Output: 3
Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
#inclde<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int NthDigit(int n) {
        long long digitLength = 1;
        long long count = 9;
        long long start = 1;

        // Step 1: find the correct digit range
        while (n > digitLength * count) {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        // Step 2: find the exact number
        long long number = start + (n - 1) / digitLength;

        // Step 3: extract the digit
        string s = to_string(number);
        return s[(n - 1) % digitLength] - '0';
    }
};