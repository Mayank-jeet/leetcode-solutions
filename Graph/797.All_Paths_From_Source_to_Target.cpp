/*
 * LeetCode:  797 - All Paths From Source to Target
 * Link: https://leetcode.com/problems/all-paths-from-source-to-target/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for recursion and ans vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int start,vector<vector<int>>& graph,vector<int> chunk){
        chunk.emplace_back(start);
        if(start==(graph.size()-1)){
            ans.emplace_back(chunk);
            return;
        }
        for(auto el:graph[start]){
            dfs(el,graph,chunk);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> chunk;
        dfs(0,graph,chunk);
        return ans;
    }
};