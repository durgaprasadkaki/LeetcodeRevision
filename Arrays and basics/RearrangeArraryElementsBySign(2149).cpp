/*
2149. Rearrange Array Elements by Sign
Medium
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  
Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n, 0);
        int posInd=0, negInd=1;
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                ans[negInd]=nums[i];
                negInd+=2;

            }
            else{
                ans[posInd]=nums[i];
                posInd+=2;
             }

        }
        return ans;
    }
};


//If any remaining happens then we can add them at the end of the array. 
/*
Given an unsorted array arr containing both positive and negative numbers.
 Your task is to rearrange the array and convert it into an array of alternate positive and
  negative numbers without changing the relative order.

Note:
- Resulting array should start with a positive integer (0 will also be considered as a positive integer).
- If any of the positive or negative integers are exhausted, then add the remaining 
integers in the answer as it is by maintaining the relative order.
- The array may or may not have the equal number of positive and negative integers.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: [9, -2, 4, -1, 5, -5, 0, -3, 2]
Explanation: The positive numbers are [9, 4, 5, 0, 2] and the 
negative integers are [-2, -1, -5, -3]. Since, we need to start with the positive integer 
first and then negative integer and so on (by maintaining the relative order as well), hence
 we will take 9 from the positive set of elements and then -2 after that 4 and then -1 and so on.*/
 #include <bits/stdc++.h>
 using namespace std;
 class Solution {
  public:
    void rearrange(vector<int> &a) {
        
        vector<int> pos, neg;
        int n = a.size();
        
        // Separate positives and negatives
        for(int i = 0; i < n; i++){
            if(a[i] >= 0){
                pos.push_back(a[i]);
            }
            else{
                neg.push_back(a[i]);
            }
        }
        
        // If positives more
        if(pos.size() > neg.size()){
            
            for(int i = 0; i < neg.size(); i++){
                a[2*i]   = pos[i];
                a[2*i+1] = neg[i];
            }
            
            int index = neg.size() * 2;
            
            for(int i = neg.size(); i < pos.size(); i++){
                a[index] = pos[i];
                index++;
            }
        }
        else{
            
            for(int i = 0; i < pos.size(); i++){
                a[2*i]   = pos[i];
                a[2*i+1] = neg[i];
            }
            
            int index = pos.size() * 2;
            
            for(int i = pos.size(); i < neg.size(); i++){
                a[index] = neg[i];
                index++;
            }
        }
    }
};