/*
 * LeetCode: 1793 - Maximum Score of a Good Subarray
 * Link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/
 * Difficulty: Hard
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k,j=k,n=nums.size();
        int ans=nums[k],minimum=nums[k];
        while(i>0 && j<n-1){
            if(nums[j+1]>=nums[i-1]){
                j++;
                minimum=min(minimum,nums[j]);
            }else{
                i--;
                minimum=min(minimum,nums[i]);
            } 
            ans=max((minimum*(j-i+1)),ans);
        }
        while(i>0){
            i--;
            minimum=min(minimum,nums[i]);
            ans=max(minimum*(j-i+1),ans);
        }
        while(j<n-1){
            j++;
            minimum=min(minimum,nums[j]);
            ans=max(minimum*(j-i+1),ans);
        }
        return ans;
    }
};