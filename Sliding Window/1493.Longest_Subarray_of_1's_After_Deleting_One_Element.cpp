/*
 * LeetCode: 1493 - Longest Subarray of 1's After Deleting One Element
 * Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int delIndex=-1,chunk=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                chunk=i-delIndex-1;
                delIndex=i;
            }else chunk++;
            if(chunk>ans) ans=chunk;
        }
        if(delIndex==-1) return ans-1;
        return ans;
    }
};