/*
 * LeetCode: 739 - Daily Temperatures
 * Link: https://leetcode.com/problems/daily-temperatures/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the array
 * Space: O(n) for the stack and the result array
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> st;
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};