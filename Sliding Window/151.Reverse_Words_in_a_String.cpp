/*
 * LeetCode: 151 - Reverse Words in a String
 * Link: https://leetcode.com/problems/remove-nodes-from-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the length of string s (input string)
 * Space: O(n) for answer string, otherwise O(l) where l is the maximum length of the word in input string
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.length();
        string chunk;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                chunk=s[i]+chunk;
            }else if(chunk.length()!=0){
                ans+=chunk;
                ans+=" ";
                chunk="";
            }
        }
        if(chunk.length()!=0){
            ans+=chunk;
        }
        if(ans.back()==' ') ans=ans.substr(0,ans.length()-1);
        return ans;
    }
};