/*
 * LeetCode: 503 - Next Greater Element II
 * Link: https://leetcode.com/problems/next-greater-element-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the array
 * Space: O(n) for the stack and the result array
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<2*n;i++){
            while(!st.empty() && nums[st.top()]<nums[i%n]){
                ans[st.top()]=nums[i%n];
                st.pop();
            }
            if(i<n) st.push(i);
        }
        return ans;
    }
};