/*
372. Super Pow
Solved
Medium
Topics
premium lock icon
Companies
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large
 positive integer given in the form of an array.

 

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
Example 3:

Input: a = 1, b = [4,3,3,8,5,2]
Output: 1
 */
#include<bits/stdc++.h>
using namespace std;    
class Solution {
public:
    int mod = 1337;

    int power(int a, int b) {
        int res = 1;
        a %= mod;
        while (b) {
            if (b % 2) res = (res * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;

        int last = b.back();
        b.pop_back();

        int part1 = power(superPow(a, b), 10);
        int part2 = power(a, last);

        return (part1 * part2) % mod;
    }
};