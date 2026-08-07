/*
 * LeetCode: 1861 - Rotating the Box
 * Link: https://leetcode.com/problems/rotating-the-box/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(m) cosidering the output array, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid){
        int n=boxGrid.size(),m=boxGrid[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            int bottom=m-1,top=m-1;
            while(top>=0 && bottom>=0){
                if(boxGrid[i][top]=='*') {
                    bottom=top-1;
                    ans[top][n-1-i]='*';
                }
                else if(boxGrid[i][top]=='#'){
                    swap(boxGrid[i][top],boxGrid[i][bottom]);
                    ans[bottom][n-1-i]='#';
                }
                top--;
                while(bottom>=0 && boxGrid[i][bottom]!='.') {
                    ans[bottom][n-1-i]=boxGrid[i][bottom];
                    bottom--;
                }
                if(top>bottom) top=bottom;
            }
        }
        return ans;
    }
};