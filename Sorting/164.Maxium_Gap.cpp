/*
 * LeetCode: 164 - Maxium Gap
 * Link: https://leetcode.com/problems/maxium-gap/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<nums.size()-1;i++){
            high=max(high,(nums[i+1]-nums[i]));
        }
        return high;
    }
};