/*
 * LeetCode: 973 - K Closest Points to Origin
 * Link: https://leetcode.com/problems/k-closest-points-to-origin/
 * Difficulty: Medium
 * Time: O(n log n)
 * Space: O(n) if we consider the space used by the output, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,vector<int>>> sq;
        for(auto el:points){
            int x1=el[0],x2=el[1];
            sq.emplace_back(x1*x1+x2*x2,el);
        }
        sort(sq.begin(),sq.end());
        vector<vector<int>> ans;
        for(int i=0;i<k;i++) ans.emplace_back(sq[i].second);
        return ans;
    }
};