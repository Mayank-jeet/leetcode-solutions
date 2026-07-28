/*
 * LeetCode:436 - Find Right Interval
 * Link: https://leetcode.com/problems/find-right-interval/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> m;
        int n=intervals.size();
        for(int i=0;i<n;i++) m[intervals[i][0]]=i;
        vector<int> ans;
        for(int i=0;i<n;i++){
            auto it = m.lower_bound(intervals[i][1]);
            ans.emplace_back(it!=m.end()?it->second:-1);
        }
        return ans;
    }
};