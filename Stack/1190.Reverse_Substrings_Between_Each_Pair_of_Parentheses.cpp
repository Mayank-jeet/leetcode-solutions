 /*
 * LeetCode: 1190 - Reverse Substrings Between Each Pair of Parentheses
 * Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * Difficulty: Medium
 * Time: O(n) is n length of input vector
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        vector<int> match(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int open=st.top();
                st.pop();
                match[open]=i;
                match[i]=open;
            }
        }
        string result;
        int direction=1;
        for(int i=0;i<n;i+=direction){
            if(s[i]=='('||s[i]==')'){
                i=match[i];
                direction=-direction;
            }
            else result.push_back(s[i]);
        }
        return result;
    }
};