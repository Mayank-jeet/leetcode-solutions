/*
 * LeetCode: 4123 - Minimum Cost to Delete Array
 * Link: https://leetcode.com/problems/minimum-cost-to-delete-array/
 * Difficulty: Hard
 * Time: O(nlogn)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long cost=(long long)nums[0]+nums[n-1];
        vector<int> middle(nums.begin()+1,nums.end()-1);
        sort(middle.begin(),middle.end());
        for(int i=0;i+1<(int)middle.size();i+=2){
            long long pairSum=(long long)middle[i]+middle[i+1];
            if(pairSum>=0) break;
            cost+=pairSum;
        }
        return cost;
    }
};