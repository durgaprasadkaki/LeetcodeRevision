/*
Find nth root of m
Difficulty: MediumAccuracy: 25.06%Submissions: 261K+Points: 4Average Time: 15m
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer 
then return -1.

Examples :

Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16
*/
#include<bits/stdc++.h>
using namespace std;    
class Solution {
  public:
  
  double multiply(double number, int n){
      double ans = 1.0;
      for(int i = 1; i <= n; i++){
          ans = ans * number;
          if(ans > 1e9) return ans;
      }
      return ans;
  }

    int nthRoot(int n, int m) {
        
        if(m == 0) return 0;
        
        int low = 1, high = m;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            double val = multiply(mid, n);
            
            if(val == m) return mid;
            else if(val < m) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
};
