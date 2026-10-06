/*
 * LeetCode: 2097 - Valid Arrangement of Pairs
 * Link: https://leetcode.com/problems/valid-arrangement-of-pairs/
 * Difficulty: Hard
 * Time: O(n) where n is number of pairs
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> deg;
        for(auto p:pairs){
            adj[p[0]].push_back(p[1]);
            deg[p[0]]++;
            deg[p[1]]--;
        }
        int start=pairs[0][0];
        for(auto [node,d]:deg){
            if(d==1){
                start=node;
                break;
            }
        }
        stack<int> st;
        st.push(start);
        vector<int> pair={start};
        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                int v=adj[curr].back();
                adj[curr].pop_back();
                st.push(v);
            }
            else{
                pair.push_back(curr);
                st.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i=pair.size()-1;i>1;i--){
            ans.push_back({pair[i],pair[i-1]});
        }
        return ans;
    }
};