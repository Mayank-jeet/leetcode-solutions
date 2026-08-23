/*
 * LeetCode: 4031 - Find All Numbers Disappeared in an Array II
 * Link: https://leetcode.com/find-all-numbers-disappeared-in-an-array-ii/
 * Difficulty: Medium
 * Time: O(nlog(n)) for sorting input vetor, else O(n) where n is number of elements in input vector
 * Space: O(k) where k is number of distinct intervals, not present in input vector 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=lower){
                lower=max(lower,nums[i]+1);
                continue;
            }
            if(nums[i]>upper) break;
            ans.push_back({lower,nums[i]-1});
            lower=nums[i]+1;
        }
        if(lower<=upper){
            ans.push_back({lower,upper});
        }
        return ans;
    }
};