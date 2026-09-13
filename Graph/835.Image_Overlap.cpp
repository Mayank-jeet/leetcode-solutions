/*
 * LeetCode: 835 - Image Overlap
 * Link: https://leetcode.com/problems/image-overlap/
 * Difficulty: Medium
 * Time: O(n^2+k1·k2) where n is the number of row or column in inuput matrix and k1 and k2 are the number of  1s in img1 and img2 respectively
 * Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> store1,store2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) store1.emplace_back(i,j);
                if(img2[i][j]==1) store2.emplace_back(i,j);
            }
        }
        int ans=0;
        vector<vector<int>> coordMap(2*n,vector<int>(2*n,0));
        for(auto el1:store1){
            for(auto el2:store2){
                int delX=el1.first-el2.first+n;
                int delY=el1.second-el2.second+n;
                ans=max(ans,++coordMap[delX][delY]);
            }
        }
        return ans;
    }
};