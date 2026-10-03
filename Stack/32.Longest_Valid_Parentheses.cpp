/*
 * LeetCode: 32 - Longest Valid Parentheses
 * Link: https://leetcode.com/problems/longest-valid-parentheses/
 * Difficulty: Hard
 * Time: O(n) where n is the length of the input string
 * Space: O(n) in worst case where all characters are '('
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int n=s.length();
        stack<int> st;
        unordered_map<int,int> dp;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else {
                if(st.empty()) continue;
                else {
                    int last=st.top();
                    st.pop();
                    int len=(i-last+1);
                    if (last-1>=0 && dp.count(last-1)) len+=dp[last-1];
                    dp[i]=len;
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};