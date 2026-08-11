/*
 * LeetCode:  547 - Number of Provinces
 * Link: https://leetcode.com/problems/number-of-provinces/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for vis(visited) vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> vis(isConnected.size(),false);
        int ans=0;
        queue<int> qe;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                vis[i]=true;
                ans++;
                qe.push(i);
            }
            while(!qe.empty()){
                int row=qe.front();
                qe.pop();
                for(int j=0;j<isConnected[row].size();j++){
                    if(vis[j]==false && isConnected[row][j]==1){
                        vis[j]=true;
                        qe.push(j);
                    }
                }
            }
        }
        return ans;
    }
};