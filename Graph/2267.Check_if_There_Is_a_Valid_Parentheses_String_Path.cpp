 /*
 * LeetCode: 2267  Check if There Is a Valid Parentheses String Path
 * Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
 * Difficulty: Hard
 * Time: O(m*n*(m+n)) where m and n are number of rows and columns in input grid respectively
 * Space: O(m*n*(m+n))
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==')' || (m+n-1)%2==1) return false;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<int> x={0,1};
        vector<int> y={1,0};
        while(!q.empty()){
            auto curr=q.front();q.pop();
            int score=curr.first;
            int xCord=curr.second.first;
            int yCord=curr.second.second;
            if(score>(m+n-1)/2) continue;
            if(xCord==m-1 && yCord==n-1 && score==0) return true;
            for(int i=0;i<2;i++){
                int newX=x[i]+xCord;
                int newY=y[i]+yCord;
                if(newX<0 || newX>=m || newY<0 || newY>=n) continue;
                int change=grid[newX][newY]=='('?1:-1;
                int newScore=score+change;
                if(newScore<0) continue;
                q.push({newScore,{newX,newY}});
            }
        }
        return false;
    }
};