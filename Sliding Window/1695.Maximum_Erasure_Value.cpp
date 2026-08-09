/*
 * LeetCode: 1695 - Maximum Erasure Value
 * Link: https://leetcode.com/problems/maximum-erasure-value/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) in the worst case for the unordered_map
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,pair<int,int>> u_map;
        int last=0,ans=0,n=nums.size(),sum=0,chunk=0;
        for(int i=0;i<n;i++){
            auto it=u_map.find(nums[i]);
            sum+=nums[i];
            if(it!=u_map.end() && it->second.first>=last){
                last=it->second.first+1;
                chunk=sum-it->second.second;
            }else{
                chunk+=nums[i];
            }
            ans=max(ans,chunk);
            u_map[nums[i]]={i,sum};
        }
        return ans;
    }
};