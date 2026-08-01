/*
 * LeetCode: 1561 - Maximum Number of Coins You Can Get
 * Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int j=piles.size()-1,i=0,ans=0;
        while(i<j){
            ans+=piles[j-1];
            j-=2;
            i++;
        }
        return ans;
    }
};