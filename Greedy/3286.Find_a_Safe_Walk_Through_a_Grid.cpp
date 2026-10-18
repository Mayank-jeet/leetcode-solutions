/*
 * LeetCode: 3286 - Find a Safe Walk Through a Grid
 * Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
 * Difficulty: Medium
 * Time: O(m·n·log(m·n)) where m is the number of rows and n is the number of columns in the grid
 * Space: O(m·n) for the priority queue and life matrix
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> life(m,vector<int>(n,INT_MIN));
        priority_queue<pair<int,pair<int,int>>> pq;
        if(grid[0][0]==1) health--;
        pq.push({health,{0,0}});
        life[0][0]=health;
        vector<int> x={0,0,1,-1};
        vector<int> y={1,-1,0,0};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int currCost=curr.first;
            int xCord=curr.second.first;
            int yCord=curr.second.second;
            for(int i=0;i<4;i++){
                int newX=xCord+x[i];
                int newY=yCord+y[i];
                if(newX<0 || newX>=m || newY<0 || newY>=n) continue;
                int newCost=currCost;
                if(grid[newX][newY]==1) newCost--;
                if(newCost<=0 || life[newX][newY]>=newCost) continue;
                life[newX][newY]=newCost; 
                pq.push({newCost,{newX,newY}});
            }
        }
        return life[m-1][n-1]>0;
    }
};