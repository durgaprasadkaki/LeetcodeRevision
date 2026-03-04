/*
229. Majority Element II
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        // Step 1: Find Potential Candidates
        for(int i = 0; i < nums.size(); i++) {
            
            if(cnt1 == 0 && nums[i] != el2) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) {
                cnt1++;
            }
            else if(nums[i] == el2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify Candidates
        cnt1 = 0; 
        cnt2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }

        vector<int> ans;
        int mini = nums.size() / 3 + 1;

        if(cnt1 >= mini) ans.push_back(el1);
        if(cnt2 >= mini) ans.push_back(el2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
/*Better
vector<int> ls;
map<int, int>mpp;
int n=nums.size();
int mini=(int)(n/3)+1;
for(int i=0; i<n; i++){
    mpp[nums[i]]++;
    if(mpp[nums[i]]==mini){
        ls.push_back(nums[i]);
    }
    if(ls.size()==2) break;
}
sort(ls.begin(), ls.end());
}*/