/*
 * LeetCode:  841 - Keys and Rooms
 * Link: https://leetcode.com/problems/keys-and-rooms/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for vis(vector) and qe(queue)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        vis[0]=true;
        queue<int> qe;
        qe.push(0);
        while(!qe.empty()){
            int row=qe.front();
            qe.pop();
            for(int i=0;i<rooms[row].size();i++){
                if(!vis[rooms[row][i]]) {
                    qe.push(rooms[row][i]);
                    vis[rooms[row][i]]=true;
                }
            }
        }
        return find(vis.begin(),vis.end(),false)==vis.end();
    }
};