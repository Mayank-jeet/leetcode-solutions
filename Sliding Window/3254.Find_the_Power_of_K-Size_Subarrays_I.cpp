/*
 * LeetCode: 3254 - Find the Power of K-Size Subarrays I
 * Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n-k) for storing ans vector, otherwise O(1) 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int unsortIndex=-1;
        for(int i=1;i<k;i++){
            if(nums[i]!=nums[i-1]+1) unsortIndex=i-1;
        }
        vector<int> ans;
        int i=k-1,n=nums.size();
        while(i<n){
            if(i-1>0 && nums[i]!=nums[i-1]+1) unsortIndex=i-1;
            if(unsortIndex>i-k){
                while(unsortIndex>i-k && i<n){
                    ans.push_back(-1);
                    if(i-1>0 && nums[i]!=nums[i-1]+1) unsortIndex=i-1;
                    i++;
                }
            }else{
                ans.emplace_back(nums[i]);
                i++;
            }
        }
        return ans;
    }
};