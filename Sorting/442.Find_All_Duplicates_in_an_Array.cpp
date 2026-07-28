/*
 * LeetCode:442 - Find All Duplicates in an Array
 * Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */
// Can we done using sorting too, but using unordered_set is faster.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> ans;
        for(int el:nums){
            if(set.count(el)!=0) ans.emplace_back(el);
            set.insert(el);
        }
        return ans;
    }
};