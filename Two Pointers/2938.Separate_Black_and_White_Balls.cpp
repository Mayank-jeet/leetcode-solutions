/*
 * LeetCode: 2938 - Separate Black and White Balls
 * Link: https://leetcode.com/problems/separate-black-and-white-balls/
 * Difficulty: Medium
 * Time: O(n) where n is the size of the input string
 * Space: O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        long long swap=0;
        int black=0,n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='0') swap+=(long long)black;
            else black++;
        }
        return swap;
    }
};