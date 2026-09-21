 /*
 * LeetCode: 3524 - Find X Value of Array I
 * Link: https://leetcode.com/problems/find-x-value-of-array-i/
 * Difficulty: Medium
 * Time: O(n*k) where n is size of input list
 * Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>ans(k,0),dp(k,0);
        for (int num:nums){
            int x=num%k;
            vector<long long>next(k,0);
            next[x]++;
            for (int r=0;r<k;r++){
                int newR=(r*x)%k;
                next[newR]+=dp[r];
            }
            for (int r=0;r<k;r++){
                ans[r]+=next[r];
            }
            dp = next;
        }
        return ans;
    }
};