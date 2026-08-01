/*
 * LeetCode: 1833 - Maximum Ice Cream Bars
 * Link: https://leetcode.com/problems/maximum-ice-cream-bars/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0,ans=0;;
        for(int el:costs){
            sum+=el;
            if(sum>coins) break;
            else ans++;
        }
        return ans;
    }
};