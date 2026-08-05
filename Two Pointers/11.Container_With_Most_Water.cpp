/*
 * LeetCode: 11 - Container With Most Water
 * Link: https://leetcode.com/problems/container-with-most-water/
 * Difficulty: Medium
 * Time: O(n) where n is the size of the input vector
 * Space: O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,ans=0,area=0;
        while(i<j){
            area=min(height[i],height[j])*(j-i);
            ans=max(area,ans);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return ans;
    }
};