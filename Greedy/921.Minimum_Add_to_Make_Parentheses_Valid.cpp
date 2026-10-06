/*
 * LeetCode: 921 - Minimum Add to Make Parentheses Valid
 * Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 * Difficulty: Medium
 * Time: O(n) where n is length of input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        for(char el:s){
            if(el=='(') open++;
            else{
                if(open>0) open--;
                else close++;
            }
        }
        return open+close;
    }
};