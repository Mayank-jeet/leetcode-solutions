/*
 * LeetCode: 309 - Best Time to Buy and Sell Stock with Cooldown
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldowns/
 * Difficulty: Medium
 * Time: O(n) where n is the length of prices
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold=-prices[0],sold=0,rest=0;
        for(int i=1;i<prices.size();i++){
            int p=prices[i];
            int nh=max(hold,rest-p);
            int ns=hold+p;
            int nr=max(rest,sold);
            hold=nh;sold=ns;rest=nr;
        }
        return max(sold,rest);
    }
};