/*
 * LeetCode: 74 - Search a 2D Matrix
 * Link: https://leetcode.com/problems/search-a-2d-matrix/
 * Difficulty: Medium
 * Time: O(log(m*n)) where m is the number of rows and n is the number of columns
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int low=0,high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/n,col=mid%n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};