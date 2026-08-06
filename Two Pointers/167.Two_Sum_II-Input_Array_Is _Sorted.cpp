/*
 * LeetCode: 167 - Two Sum II - Input Array Is Sorted
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) considering the output array, otherwise O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1,sum=0;
        vector<int> ans;
        while(left<right){
            sum=numbers[left]+numbers[right];
            if(sum==target){
                ans={left+1,right+1};
                break;
            }
            else if(sum>target) right--;
            else left++;
        }
        return ans;
    }
};