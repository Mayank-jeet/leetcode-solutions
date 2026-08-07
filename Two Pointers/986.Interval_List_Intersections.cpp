/*
 * LeetCode: 986 - Interval List Intersections
 * Link: https://leetcode.com/problems/interval-list-intersections/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) for storing the answer otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size(),m=secondList.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<n && j<m){
            if(firstList[i][0]<=secondList[j][0] && firstList[i][1]>=secondList[j][0]){
                vector<int> temp={secondList[j][0],min(firstList[i][1],secondList[j][1])};
                ans.emplace_back(temp);
                if(firstList[i][1]<=secondList[j][1])i++;
                else j++;
            }else if(secondList[j][0]<=firstList[i][0] && secondList[j][1]>=firstList[i][0]){
                vector<int> temp={firstList[i][0],min(firstList[i][1],secondList[j][1])};
                ans.emplace_back(temp);
                if(firstList[i][1]>=secondList[j][1]) j++;
                else i++;
            }else {
                if(firstList[i][1]<secondList[j][0]) i++;
                else j++;
            }
        }
        return ans;
    }
};