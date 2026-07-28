/*
 * LeetCode:347 - Top K Frequent Elements
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(n)
 */n
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int el:nums){
            map[el]++;
        }
        vector<pair<int,int>> vec;
        for(auto [key,val]:map) vec.emplace_back(val,key);
        sort(vec.begin(),vec.end(),[](const pair<int,int> &a,const pair<int,int>&b){
            if(a.first!=b.first) return a.first>b.first;
            else return a.second<b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++) ans.emplace_back(vec[i].second);
        return ans;
    }
};