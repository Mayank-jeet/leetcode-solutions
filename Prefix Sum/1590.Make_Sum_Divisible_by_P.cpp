/*
 * LeetCode: 1590 - Make Sum Divisible by P
 * Link: https://leetcode.com/problems/make-sum-divisible-by-p/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(p) where p is distinct mod values
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> u_map={{0,-1}};
        int ans=INT_MAX,n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0LL),chunkSum=0;
        if(sum%p==0) return 0;
        for(int i=0;i<n;i++){
            chunkSum+=(long long)nums[i];
            u_map[chunkSum%p]=i;
            int extra=(p-((sum-chunkSum)%p))%p;
            if(u_map.count(extra)!=0) ans=min(ans,(i-u_map[extra]));
        }
        if(ans>=n) return -1;
        return ans;
    }
};