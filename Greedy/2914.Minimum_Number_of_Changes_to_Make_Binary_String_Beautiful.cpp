/*
 * LeetCode: 2914 -Minimum Number of Changes to Make Binary String Beautiful
 * Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i+=2) if(s[i]!=s[i+1]) ans++;
        return ans;
    }
};