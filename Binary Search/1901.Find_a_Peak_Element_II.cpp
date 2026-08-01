/*
 * LeetCode: 1901 - Find a Peak Element II
 * Link: https://leetcode.com/problems/find-a-peak-element-ii/
 * Difficulty: Medium
 * Time: O(log(n)) where n is the number of elements in the array
 * Space: O(n) if we consider the space used by the input matrix, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int low=0,high=n-1;
        vector<int> ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxEl=max_element(mat[mid].begin(),mat[mid].end())-mat[mid].begin();
            if(mid>0?mat[mid][maxEl]<mat[mid-1][maxEl]:false) high=mid-1;
            else if(mid<n-1?mat[mid][maxEl]<mat[mid+1][maxEl]:false) low=mid+1;
            else{
                ans={mid,maxEl};
                return ans;
            }
        }
        return ans;
    }
};