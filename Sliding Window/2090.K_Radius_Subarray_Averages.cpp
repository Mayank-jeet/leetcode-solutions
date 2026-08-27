/*
 * LeetCode: 2090 - K Radius Subarray Averages
 * Link: https://leetcode.com/problems/k-radius-subarray-averages/
 * Difficulty: Medium
 * Time: O(n) where n is size of input vector
 * Space: O(n) for storing answer vector, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<k && i<n;i++) sum+=(long long)nums[i];
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i-k-1>=0) sum-=nums[i-k-1];
            if(i+k<n) sum+=(long long )nums[i+k];
            if(i-k<0 || i+k>=n) ans.push_back(-1);
            else ans.push_back(sum/(2*k+1));
        }
        return ans;
    }
};