/*
 * LeetCode: 1310 - XOR Queries of a Subarray
 * Link: https://leetcode.com/problems/xor-queries-of-a-subarray/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) space used for vec and ans vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> vec(arr.size()+1);
        vec[0]=0;
        int n=arr.size(),m=queries.size();
        int xor1=0;
        for(int i=0;i<n;i++){
            xor1^=arr[i];
            vec[i+1]=xor1;
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            ans.emplace_back(vec[queries[i][1]+1]^vec[queries[i][0]]);
        }
        return ans;
    }
};