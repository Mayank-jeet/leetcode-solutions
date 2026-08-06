/*
 * LeetCode: 647 - Palindromic Substrings
 * Link: https://leetcode.com/problems/palindromic-substrings/
 * Difficulty: Medium
 * Time: O(n^2) for checking all substrings + O(n) for checking if a substring is palindrome
 * Space: O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool palindrome(string chunk){
        int n=chunk.length();
        for(int i=0;i<n/2;i++){
            if(chunk[i]!=chunk[n-1-i]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j+i<=n;j++){
                if(palindrome(s.substr(j,i))) ans++;
            }
        }
        return ans;
    }
};