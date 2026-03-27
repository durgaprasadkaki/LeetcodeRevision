/*
Implement Floor and Ceil
Difficulty: EasyAccuracy: 52.54%Submissions: 50K+Points: 2
Given a sorted array arr[] and a number x, the task is to find the floor and ceil of x in this given array.
The floor of a number is defined as the largest element in the sorted array which is less than or equal to the 
given number.
The ceil of a number is defined as the smallest element in the sorted array which is greater than or equal to the
 given number.

Examples :

Input: arr[] = [1, 2, 4, 6, 8], x = 5
Output: {4, 6}
Explanation: 4 is the largest element ≤ 5 and 6 is the smallest element ≥ 5.
Input: arr[] = [1, 2, 4, 6, 8], x = 4
Output: {4, 4}
Explanation: 4 is both the largest element ≤ 4 and the smallest element ≥ 4.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    pair<int,int> floorAndCeil(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int floor = -1;
        int ceil = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                floor = arr[mid];
                ceil = arr[mid];
                break;
            }
            else if(arr[mid]>x){
                ceil = arr[mid];
                high = mid-1;
            }
            else{
                floor = arr[mid];
                low = mid+1;
            }
        }
        return {floor,ceil};
    }
};