/*
 * LeetCode:  3568 - Minimum Moves to Clean the Classroom
 * Link: https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
 * Difficulty: Medium
 * Time: O(m*n*2^L) where m is number of rows, n is number of columns and L is number of lockers
 * Space: O(m*n*2^L)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();
        int sr=-1,sc=-1;
        int cnt=0;
        vector<vector<int>> id(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                if(classroom[i][j]=='L'){
                    id[i][j]=cnt++;
                }
            }
        }
        int masks=1<<cnt;
        int fullMask=masks-1;
        vector<vector<vector<int>>> best;
        best.resize(m,vector<vector<int>>(n,vector<int>(masks,-1)));
        struct State{
            int r,c;
            int mask;
            int en;
            int dist;
        };
        queue<State> q;
        q.push({sr,sc,0,energy,0});
        best[sr][sc][0]=energy;
        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};
        while(!q.empty()){
            State crr=q.front();
            q.pop();
            int r=crr.r;
            int c=crr.c;
            int mask=crr.mask;
            int en=crr.en;
            int dist=crr.dist;
            if(mask==fullMask) return dist;
            if(en==0) continue;
            for(int d=0;d<4;d++){
                int nr=r+dr[d];
                int nc=c+dc[d];
                if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
                if(classroom[nr][nc]=='X') continue;
                int newEn=en-1;
                int newMask=mask;
                if(classroom[nr][nc]=='L') newMask|=(1<<id[nr][nc]);
                if(classroom[nr][nc]=='R') newEn=energy;
                if(best[nr][nc][newMask]>=newEn) continue;
                best[nr][nc][newMask]=newEn;
                q.push({nr,nc,newMask,newEn,dist+1});
            }
        }
        return -1;
    }
};