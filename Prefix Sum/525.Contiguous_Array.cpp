/*
 * LeetCode: 525 - Contiguous Array
 * Link: https://leetcode.com/problems/contiguous-array/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) space used for unordered_map
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> u_map{{0,-1}};
        int n=nums.size(),ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]==1?1:-1;
            if(u_map.count(sum)!=0) ans=max(ans,i-u_map[sum]);
            else u_map[sum]=i;
        }
        return ans;
    }
};