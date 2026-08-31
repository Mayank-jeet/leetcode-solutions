/*
 * LeetCode: 438 - Find All Anagrams in a String
 * Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * Difficulty: Medium
 * Time: O(max(p_length,s_length)) where p_length and s_length are lengths of input strings s and p respectively
 * Space: O(u) where u is number of unique elements in input sting p
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int s_length=s.length(),p_length=p.length();
        if(s_length<p_length) return ans;
        unordered_map<char,int> u_map;
        int distEl=0;
        for(char el:p){
            u_map[el]++;
            if(u_map[el]==1) distEl++;
        }
        for(int i=0;i<s_length;i++){
            if(i-p_length>=0){
                if(u_map.count(s[i-p_length])!=0){
                    u_map[s[i-p_length]]++;
                    if(u_map[s[i-p_length]]==0) distEl--;
                    else if(u_map[s[i-p_length]]==1) distEl++;
                }
            }
            if(u_map.count(s[i])!=0){
                u_map[s[i]]--;
                if(u_map[s[i]]==0) distEl--;
                else if(u_map[s[i]]==-1) distEl++;
                if(distEl==0) ans.push_back(i-p_length+1);
            }
        }
        return ans;
    }
};