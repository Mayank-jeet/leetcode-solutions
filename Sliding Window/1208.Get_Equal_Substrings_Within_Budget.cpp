/*
 * LeetCode: 1208 - Get Equal Substrings Within Budget
 * Link: https://leetcode.com/problems/get-equal-substrings-within-budget/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost=0,left=0,n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            cost+=abs(s[i]-t[i]);
            if(cost>maxCost){
                cost-=abs(s[left]-t[left]);
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};