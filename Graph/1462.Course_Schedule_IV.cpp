/*
 * LeetCode:  1462 - Course Schedule IV
 * Link: https://leetcode.com/problems/course-schedule-iv/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for vis and adj vectors, as well as stack space used for recursion
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs( vector<vector<int>>& adj,int& end,int index,vector<bool>& vis,bool& check){
        if(check) return;
        for(auto el:adj[index]){
            if(!vis[el]){
                vis[el]=true;
                if(el==end) check=true;
                dfs(adj,end,el,vis,check);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(auto el:prerequisites) {
            int u=el[0],v=el[1];
            adj[u].emplace_back(v);
        }
        vector<bool> ans;
        for(auto el:queries){
            bool check=false;
            vector<bool> vis(numCourses,false);
            vis[el[0]]=true; 
            dfs(adj,el[1],el[0],vis,check);
            ans.emplace_back(check);
        }
        return ans;
    }
};