/*
 * LeetCode: 123 - Best Time to Buy and Sell Stock III
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Difficulty: Hard
 * Time: O(n) where n is the length of the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1=INT_MIN,buy2=INT_MIN;
        int sold1=0,sold2=0;
        for(int p:prices){
            buy1=max(buy1,-p);
            sold1=max(sold1,buy1+p);
            buy2=max(buy2,sold1-p);
            sold2=max(sold2,buy2+p);
        }
        return sold2;
    }
};