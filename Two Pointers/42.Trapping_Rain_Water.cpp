/*
 * LeetCode: 42 - Trapping Rain Water
 * Link: https://leetcode.com/problems/trapping-rain-water/
 * Difficulty: Hard
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        vector<int> leftMax={height[0]};
        vector<int> rightMax={height[height.size()-1]};
        int n=height.size();
        for(int i=2;i<n-1;i++){
            leftMax.emplace_back(max(height[i-1],leftMax.back()));
            rightMax.emplace_back(max(height[n-i],rightMax.back()));
        }
        int m=rightMax.size();
        int ans=0;
        for(int i=0;i<m;i++){
            int waterLevel=min(leftMax[i],rightMax[m-1-i])-height[i+1];
            if(waterLevel>0) ans+=waterLevel;
        }
       return ans; 
    }
};