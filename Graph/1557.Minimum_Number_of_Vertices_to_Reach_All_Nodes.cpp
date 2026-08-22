/*
 * LeetCode: 1557 - Minimum Number of Vertices to Reach All Nodes
 * Link: https://leetcode.com/minimum-number-of-vertices-to-reach-all-nodes/
 * Difficulty: Medium
 * Time: O(V+E) where V is number of vertices and E is number of edges
 * Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // All the node with no in-edge will be answer
        vector<bool> visited(n,false);
        int size=edges.size();
        for(int i=0;i<size;i++) visited[edges[i][1]]=true;
        vector<int> ans;
        for(int i=0;i<n;i++) if(!visited[i]) ans.push_back(i);
        return ans;
    }
};