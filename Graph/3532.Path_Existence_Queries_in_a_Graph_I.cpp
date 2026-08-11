/*
 * LeetCode:  3532 - Path Existence Queries in a Graph I
 * Link: https://leetcode.com/problems/find-champion-ii/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for dist and ans vectors
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> dist(n,0);
        int exceed=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) exceed++;
            dist[i]=exceed;
        }
        vector<bool> ans;
        for(auto el:queries){
            if(dist[el[1]]==dist[el[0]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};