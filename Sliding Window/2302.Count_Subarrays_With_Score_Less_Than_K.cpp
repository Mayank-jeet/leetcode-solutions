/*
 * LeetCode: 2302 - Count Subarrays With Score Less Than K
 * Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
 * Difficulty: Hard
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left=-1,n=nums.size();
        long long sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=(long long)nums[i];
            while(sum*(i-left)>=k){
                left++;
                sum-=nums[left];
            }
            ans+=(i-left);
        }
        return ans;
    }
};