#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int gcd(int a, int b) {
        // Euclidean Algorithm
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
