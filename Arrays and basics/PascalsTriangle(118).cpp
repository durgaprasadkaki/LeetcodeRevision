/*
118. Pascal's Triangle
Solved
Easy
Topics
premium lock icon
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
               vector<vector<int>> result;
               vector<int>prev(numRows, 0);
               vector<int>curr(numRows, 0);
               for(int i=0; i<numRows; i++){
                curr[0]=1;
                curr[i]=1;
                for(int j=1; j<i; j++){
                        curr[j]=prev[j-1]+prev[j];
                }
                vector<int> row;
                for(int j=0; j<=i; j++){
                    row.push_back(curr[j]);
                }
                result.push_back(row);
                prev=curr;
                   }
                   return result;
    }
};
/*
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }*/