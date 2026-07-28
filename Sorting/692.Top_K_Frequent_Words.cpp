/*
 * LeetCode: 692 - Top K Frequent Words
 * Link: https://leetcode.com/problems/top-k-frequent-words/
 * Difficulty: Medium
 * Time: O(nlog(n))
 * Space:O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(auto el:words) map[el]+=1;
        vector<pair<int,string>> vec;
        for(auto [key,val]:map) vec.emplace_back(val,key);
        sort(vec.begin(), vec.end(), [](auto& a, auto& b){
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;                        
        });
        vector<string> ans;
        for(int i=0;i<k;i++) ans.emplace_back(vec[i].second);
        return ans;
    }
};