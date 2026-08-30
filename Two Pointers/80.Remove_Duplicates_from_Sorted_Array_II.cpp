/*
 * LeetCode: 80 - Remove Duplicates from Sorted Array II
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Difficulty: Medium
 * Time: O(n) where n is size of input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(auto el:nums){
            if(i==0||i==1||nums[i-2]!=el){
                nums[i]=el;
                i++;
            }
        }
        return i;
    }
};