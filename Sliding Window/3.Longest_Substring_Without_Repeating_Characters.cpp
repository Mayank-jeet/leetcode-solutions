/*
 * LeetCode: 3 - Longest Substring Without Repeating Characters
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) if all the characters are unique, otherwise O(min(n,m)) where m is the size of the character sets
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> u_map;
        int n=s.length(),left=0,ans=0;
        for(int i=0;i<n;i++){
            if(u_map.count(s[i])!=0){
                left=max(left,u_map[s[i]]+1);
            }
            u_map[s[i]]=i;
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};