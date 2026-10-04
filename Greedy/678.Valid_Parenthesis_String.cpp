/*
 * LeetCode: 678 - Valid Parenthesis String
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 * Difficulty: Medium
 * Time: O(n) where n is length of input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int minimum=0;
        int maximum=0;
        for(char el:s){
            if(el=='('){
                minimum++;
                maximum++;
            }
            else if(el==')'){
                minimum--;
                maximum--;
            }
            else{
                minimum--;
                maximum++;
            }
            if(maximum<0) return false;
            minimum=max(minimum,0);
        }
        return minimum==0;
    }
};