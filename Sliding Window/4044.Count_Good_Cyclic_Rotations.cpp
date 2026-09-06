/*
 * LeetCode: 4044 - Count Good Cyclic Rotations
 * Link: https://leetcode.com/problems/count-good-cyclic-rotations/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long sum1=0,sum2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i<n/2) sum1+=nums[i];
            else sum2+=nums[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(sum1>sum2) ans++;
            sum2+=nums[i];
            sum2-=nums[(i+n/2)%n];
            sum1+=nums[(i+n/2)%n];
            sum1-=nums[i];
        }
        return ans;
    }
};