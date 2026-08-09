/*
 * LeetCode: 2149 - Rearrange Array Elements by Sign
 * Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
 * Difficulty: Medium
 * Time: O(n) 
 * Space: O(n) considering the output array, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0,j=1,n=nums.size();
        vector<int> ans(n);
        for(int k=0;k<n;k++){
            if(nums[k]>0){
                ans[i]=nums[k];
                i+=2;
            }else{
                ans[j]=nums[k];
                j+=2;
            }
        }
        return ans;
    }
};