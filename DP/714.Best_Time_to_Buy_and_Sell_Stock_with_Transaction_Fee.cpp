/*
 * LeetCode: 714 - Best Time to Buy and Sell Stock with Transaction Fee
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold=-prices[0],sold=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            int p=prices[i];
            int nh=max(hold,sold-p);
            int ns=max(sold,hold+p-fee);
            hold=nh,sold=ns;
        }
        return sold;
    }
};