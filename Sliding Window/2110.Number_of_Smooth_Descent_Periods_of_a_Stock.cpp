/*
 * LeetCode: 2110 - Number of Smooth Descent Periods of a Stock
 * Link: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long len=1,ans=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            ans+=len;
            if(prices[i]!=prices[i+1]+1) len=1;
            else len++;
        }
        return ans+len;
    }
};