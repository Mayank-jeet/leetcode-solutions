/*
 * LeetCode: 946 - Validate Stack Sequences
 * Link: https://leetcode.com/problems/validate-stack-sequences/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the array
 * Space: O(n) for the stack and the result array
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0,j=0;
        while(i<pushed.size() || j<popped.size()){
            if(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
            else if(i<pushed.size()){
                s.push(pushed[i]);
                i++;
            }else return false;
        }
        return true;
    }
};