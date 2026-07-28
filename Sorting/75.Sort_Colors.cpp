/*
 * LeetCode: 75 - Sort Colors
 * Link: https://leetcode.com/problems/sort-colors/
 * Difficulty: Medium
 * Time: O(n), where n is the size of nums
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=count(nums.begin(),nums.end(),0);
        int count1=count(nums.begin(),nums.end(),1);
        int count2=count(nums.begin(),nums.end(),2);
        int i = 0;
        while (count0--) nums[i++] = 0;
        while (count1--) nums[i++] = 1;
        while (count2--) nums[i++] = 2;
    }
};