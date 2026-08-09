/*
 * LeetCode: 1839 - Longest Substring Of All Vowels in Order
 * Link: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans=0;
        string s="aeiou";
        int first=0,second=1;
        int len=0;
        for(char el:word){
            if(el==s[first]) len++;
            else if(second<5 && el==s[second] && len>first){
                first++;
                second++;
                len++;
            }else{
                first=0;
                second=1;
                if(el=='a') len=1;
                else len=0;
            }
            if(first==4) ans=max(len,ans);
        }
        return ans;
    }
};