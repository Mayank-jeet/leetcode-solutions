/*
 * LeetCode: 15 - 3Sum
 * Link: https://leetcode.com/problems/3sum/
 * Difficulty: Medium
 * Time: O(n^2) where n is the size of the input vector
 * Space: O(n) considering the space used by the answer vector otherwise O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    j++;
                    k--;
                    ans.emplace_back(temp);
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};