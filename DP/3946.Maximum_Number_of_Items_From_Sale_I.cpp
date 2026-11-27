/*
 * LeetCode: 3946 - Maximum Number of Items From Sale I
 * Link: https://leetcode.com/problems/maximum-number-of-items-from-sale-i/
 * Difficulty: Medium
 * Time: O(n*B+Tlog(T)) where n is items.size(), B is budget, and T is max factor.
 * Space: O(T+B)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items,int budget) {
        int top=0,cheapest=INT_MAX;
        for(auto& it:items) top=max(top,it[0]),cheapest=min(cheapest,it[1]);
        vector<int> have(top+1),gains(top+1),best(budget+1);
        for(auto& it:items) have[it[0]]++;
        for(int f=1;f<=top;f++)
            for(int m=f;m<=top;m+=f) gains[f]+=have[m];
        for(int m=0;m<=budget;m++) best[m]=m/cheapest;
        for(auto& it:items) {
            int p=it[1],g=gains[it[0]];
            if(g>p/cheapest)
                for(int m=budget;m>=p;m--) best[m]=max(best[m],best[m-p]+g);
        }
        return best[budget];
    }
};