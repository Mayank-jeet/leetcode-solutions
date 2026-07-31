/*
 * LeetCode: 1288 - Remove Covered Intervals
 * Link: https://leetcode.com/problems/remove-covered-intervals/
 * Difficulty: Medium
 * Time: O(n log n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0]; 
        });
        int ans=0,maxCount=0;
        for(auto el:intervals){
            if(el[1]>maxCount){
                maxCount=el[1];
                ans++;
            }
        }
        return ans;
    }
};