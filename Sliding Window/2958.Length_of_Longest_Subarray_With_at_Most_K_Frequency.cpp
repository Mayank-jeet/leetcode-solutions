/*
 * LeetCode: 2958 - Length of Longest Subarray With at Most K Frequency
 * Link: https://leetcode.com/length-of-longest-subarray-with-at-most-k-frequency/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(u) where u is number of unique elements in input vector 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0,last=0;
        unordered_map<int,int> u_map;
        for(int i=0;i<n;i++){
            u_map[nums[i]]++;
            if(u_map[nums[i]]>k){
                while(nums[last]!=nums[i]){
                    u_map[nums[last]]--;
                    last++;
                }
                u_map[nums[i]]--;
                last++;
            }
            ans=max(ans,i-last+1);
        }
        return ans;
    }
};