/*
128. Longest Consecutive Sequence
Solved
Medium
Topics
premium lock icon
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
*/
//optimal
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) {
            if (!st.count(num - 1)) {
                int x = num;
                int cnt = 1;

                while (st.count(x + 1)) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
//Better
#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    int longest = 1;
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) continue;

        if (nums[i] == nums[i - 1] + 1) {
            count++;
        } else {
            count = 1;
        }

        longest = max(longest, count);
    }

    return longest;
}

