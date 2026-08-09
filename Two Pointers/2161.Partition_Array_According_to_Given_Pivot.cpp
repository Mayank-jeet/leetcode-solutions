/*
 * LeetCode: 2161 - Partition Array According to Given Pivot
 * Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
 * Difficulty: Medium
 * Time: O(n) 
 * Space: O(n);
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> small,large;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) small.push(nums[i]);
            else if(nums[i]>pivot) large.push(nums[i]);
            else count++;
        }
        nums.clear();
        while(!small.empty()){
            nums.emplace_back(small.front());
            small.pop();
        }
        for(int i=0;i<count;i++) nums.emplace_back(pivot);
        while(!large.empty()){
            nums.emplace_back(large.front());
            large.pop();
        }
        return nums;
    }
};