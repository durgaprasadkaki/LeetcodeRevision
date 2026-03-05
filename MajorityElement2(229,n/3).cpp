/*
 * Majority Element II
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int cnt1=0, cnt2=0;
      int n=nums.size();
      int maj1=INT_MIN, maj2=INT_MIN;
      for(int i=0; i<n; i++){
        if(cnt1==0 && nums[i]!=maj2){
            maj1=nums[i];
            cnt1++;
        }
        else if(cnt2==0 && nums[i]!=maj1){
            maj2=nums[i]; 
            cnt2++;
        }
        else if(nums[i]==maj1){
            cnt1++;
        }
        else if(nums[i]==maj2){
            cnt2++;
        }
        else {
            cnt1--; cnt2--;
        }
      }
      cnt1=0, cnt2=0;
      for(int i=0; i<n; i++){
        if(nums[i]==maj1) cnt1++;
        if(nums[i]==maj2) cnt2++;
      }
     vector<int>ans;
     int condi = n/3;
        if(cnt1>condi) ans.push_back(maj1);
        if(cnt2>condi) ans.push_back(maj2);
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