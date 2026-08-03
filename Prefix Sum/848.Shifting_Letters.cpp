/*
 * LeetCode: 848 - Shifting Letters
 * Link: https://leetcode.com/problems/shifting-letters/
 * Difficulty: Medium
 * Time: O(n) wwhere n size of the input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum=0;
        for(int el:shifts) sum+=el;
        int shift=sum%26;
        int n=s.length();
        for(int i=0;i<n;i++){
            int shift = sum % 26;
            s[i] = 'a' + (s[i]-'a'+shift) % 26;
            sum -= shifts[i];
        }
        return s;
    }
};