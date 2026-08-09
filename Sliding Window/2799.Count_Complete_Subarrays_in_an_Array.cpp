/*
 * LeetCode: 2799 - Count Complete Subarrays in an Array
 * Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) for unordered_map and unordered_set
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> u_set;
        int n=nums.size(),distinct=0;
        for(int i=0;i<n;i++){
            if(u_set.count(nums[i])==0){
                u_set.insert(nums[i]);
                distinct++;
            }
        }
        unordered_map<int,int> u_map;
        int left=0,diffEl=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(u_map[nums[i]]==0) diffEl++;
            u_map[nums[i]]++;
            if(diffEl==distinct){
                while(left<i){
                    if(u_map[nums[left]]==1) break;
                    u_map[nums[left]]--;
                    left++;
                }
                ans+=(left+1);
            }
        }
        return ans;
    }
};