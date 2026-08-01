/*
 * LeetCode: 240 - Search a 2D Matrix II
 * Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
 * Difficulty: Medium
 * Time: O(log(m+n)) where m is the number of rows and n is the number of columns
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int row=0,col=n-1;
        while(row<m && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};