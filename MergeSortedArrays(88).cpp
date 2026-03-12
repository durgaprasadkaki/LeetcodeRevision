/*
88. Merge Sorted Array
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int left = m-1;
        int right = 0;

        while(left >= 0 && right < n){
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else break;
        }

        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());

        // copy nums2 into nums1
        for(int i=0;i<n;i++){
            nums1[m+i] = nums2[i];
        }
    }
};
/*
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> nums3(m+n);

        int left = 0;
        int right = 0;
        int index = 0;

        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                nums3[index++] = nums1[left++];
            }
            else{
                nums3[index++] = nums2[right++];
            }
        }

        while(left < m){
            nums3[index++] = nums1[left++];
        }

        while(right < n){
            nums3[index++] = nums2[right++];
        }

        for(int i = 0; i < m+n; i++){
            nums1[i] = nums3[i];
        }
    }*/