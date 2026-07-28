/*
 * LeetCode:451 - Sort Characters By Frequency
 * Link: https://leetcode.com/problems/sort-characters-by-frequency/
 * Difficulty: Medium
 * Time: O(nlog(n))
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char el:s){
            map[el]+=1;
        }
        string ans;
        vector<pair<char,int>> srt(map.begin(),map.end());
        sort(srt.begin(), srt.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        for(auto [ch,freq]:srt){
            string chunk(freq,ch);
            ans+=chunk;
        }
        return ans;
    }
};