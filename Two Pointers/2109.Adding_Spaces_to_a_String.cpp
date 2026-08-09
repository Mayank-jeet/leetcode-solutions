/*
 * LeetCode: 21090 - Adding Spaces to a String
 * Link: https://leetcode.com/problems/adding-spaces-to-a-string/
 * Difficulty: Medium
 * Time: O(n) 
 * Space: O(n) considering the output string, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n=s.length(),m=spaces.size(),j=0;
        for(int i=0;i<n;i++){
            if(j<m && spaces[j]==i) {
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};