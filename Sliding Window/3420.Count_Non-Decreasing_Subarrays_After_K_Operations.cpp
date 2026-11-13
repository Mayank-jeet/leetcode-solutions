/*
 * LeetCode: 3420. Count Non-Decreasing Subarrays After K Operations
 * Link: https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/
 * Difficulty: Medium
 * Time: O(n) where n is length of input vector
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), r=n-1;
        deque<int> dq;
        long long ans=0, cost=0;
        for(int l=n-1;l>=0;l--){
            int x=nums[l];
            while(!dq.empty() && nums[dq.front()]<=x){
                int s=dq.front(); dq.pop_front();
                int e=dq.empty()?r+1:dq.front();
                cost+=1LL*(x-nums[s])*(e-s);
            }
            dq.push_front(l);
            while(cost>k){
                cost-=nums[dq.back()]-nums[r];
                if(dq.back()==r) dq.pop_back();
                r--;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};