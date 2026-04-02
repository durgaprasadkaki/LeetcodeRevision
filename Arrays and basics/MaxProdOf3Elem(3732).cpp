/*
3732. Maximum Product of Three Elements After One Replacement
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums.

You must replace exactly one element in the array with any integer value in the range [-105, 105] (inclusive).

After performing this single replacement, determine the maximum possible product of any three elements at 
distinct indices from the modified array.

Return an integer denoting the maximum product achievable.

 

Example 1:

Input: nums = [-5,7,0]

Output: 3500000

Explanation:

Replacing 0 with -105 gives the array [-5, 7, -105], which has a product (-5) * 7 * (-105) = 3500000. 
The maximum product is 3500000.
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        long long min1 = nums[0], min2 = nums[1], min3 = nums[2];
        long long max1 = nums[n-1], max2 = nums[n-2], max3 = nums[n-3];

        long long ans = LLONG_MIN;

        // 1. No replacement
        ans = max(ans, max1 * max2 * max3);
        ans = max(ans, min1 * min2 * max1);

        // 2. Replace with +100000
        ans = max(ans, 100000LL * max1 * max2);
        ans = max(ans, 100000LL * min1 * min2);

        // 3. Replace with -100000
        ans = max(ans, -100000LL * max1 * max2);
        ans = max(ans, -100000LL * min1 * min2);
        ans = max(ans, -100000LL * min1 * max1); //  FIX

        return ans;
    }
};
