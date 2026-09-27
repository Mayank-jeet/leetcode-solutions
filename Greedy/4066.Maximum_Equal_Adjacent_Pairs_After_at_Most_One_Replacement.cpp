/*
 * LeetCode: 4066 - Maximum Equal Adjacent Pairs After at Most One Replacement
 * Link: https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/
 * Difficulty: Medium
 * Time: O(n) where n is length of input vector
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<int,unordered_map<int,int>> replace_map;
        unordered_map<int,int> pairMap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0){
                if(nums[i-1]!=nums[i]) replace_map[nums[i-1]][nums[i]]++;
            }
            if(i<n-1){
                if(nums[i+1]==nums[i]) pairMap[nums[i]]++;
                else replace_map[nums[i+1]][nums[i]]++;
            }
        }
        int baseline=0;
        for(auto& el:pairMap) baseline+=el.second;
        int ans=baseline;
        for(auto& el:replace_map){
            for(auto& val:el.second){
                ans=max(ans,baseline+val.second);
            }
        }
        return ans;
    }
};