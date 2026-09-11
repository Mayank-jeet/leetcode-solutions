/*
 * LeetCode: 3341 - Find Minimum Time to Reach Last Room I
 * Link: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
 * Difficulty: Medium
 * Time: O(m*n*log(m*n)) where m is the number of rows and n is the number of columns in moveTime
 * Space: O(m*m) for the distance matrix and priority queue
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m=moveTime.size(),n=moveTime[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        struct schema{
            int cost;
            pair<int,int> coordinate;
            bool operator>(const schema& other) const {
                return cost > other.cost;
            }
        };
        schema startNode={dist[0][0],{0,0}};
        priority_queue<schema, vector<schema>, greater<schema>> pq;
        pq.push(startNode);
        vector<int> x={0,0,1,-1};
        vector<int> y={1,-1,0,0};
        while(!pq.empty()){
            schema curr=pq.top();pq.pop();
            int cost=curr.cost;
            int currX=curr.coordinate.first;
            int currY=curr.coordinate.second;
            for(int i=0;i<4;i++){
                int newX=currX+x[i];
                int newY=currY+y[i];
                if(newX<0 || newX>=n || newY<0 || newY>=m) continue;
                int newCost=max(cost,moveTime[newY][newX])+1;
                if(dist[newY][newX]>newCost){
                    schema newNode={newCost,{newX,newY}};
                    dist[newY][newX]=newCost;
                    pq.push(newNode);
                }
            }
        }
        return dist[m-1][n-1];
    }
};