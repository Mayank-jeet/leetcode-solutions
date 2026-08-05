/*
 * LeetCode: 18 - 4Sum
 * Link: https://leetcode.com/problems/4sum/
 * Difficulty: Medium
 * Time: O(n^3) where n is the size of the input vector
 * Space: O(n) considering the space used by the answer vector otherwise O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-3;i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n-2;j++){
            if(j!=i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1,l=n-1;
            while(k<l){
                long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum>target) l--;
                else if(sum<target) k++;
                else{
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.emplace_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
    }
};