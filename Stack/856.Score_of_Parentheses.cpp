/*
 * LeetCode: 856 - Score of Parentheses
 * Link: https://leetcode.com/problems/score-of-parentheses/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the string
 * Space: O(n) for the stack in worst case
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char el:s){
            if(el=='(') st.push(0);
            else{
                int v=st.top();st.pop();
                int w=st.top();st.pop();
                st.push(w+max(2*v,1));
            }
        }
        return st.top();
    }
};