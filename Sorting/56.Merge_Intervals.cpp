/*
 * LeetCode: 56 -  Merge Intervals
 * Link: https://leetcode.com/problems/merge-intervals/
 * Difficulty: Medium
 * Time: O(n log n), where n is the number of intervals
 * Space: O(log n) to O(n) auxiliary
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(auto el:intervals){
            if(ans.size()==0 || ans.back()[1]<el[0]) ans.emplace_back(el);
            else{
                if(ans.back()[1]<el[1]) ans.back()[1]=el[1];
            } 
        }
        return ans;
    }
};