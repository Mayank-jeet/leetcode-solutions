/*
 * LeetCode: 49 - Group Anagrams
 * Link: https://leetcode.com/problems/group-anagrams/
 * Difficulty: Medium
 * Time: O(nklog k), where n is the length of strs, and k is the maximum length of a string in strs
 * Space: O(nk)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> ans;
        for(auto el:strs){
            string copy=el;
            sort(copy.begin(),copy.end());
            map[copy].emplace_back(el);
        }
        for(auto [key,val]:map){
            ans.emplace_back(val);
        }
        return ans;
    }
};