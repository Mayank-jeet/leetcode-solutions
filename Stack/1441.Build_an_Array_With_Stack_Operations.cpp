/*
 * LeetCode: 1441 - Build an Array With Stack Operations
 * Link: https://leetcode.com/problems/build-an-array-with-stack-operations/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the target array
 * Space: O(1) excluding the output array
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int num=1;
        vector<string> ans;
        for(int i=0;i<target.size();i++){
            while(target[i]!=num){
                ans.emplace_back("Push");
                ans.emplace_back("Pop");
                num++;
            }
            ans.emplace_back("Push");
            num++;
        }
        return ans;
    }
};