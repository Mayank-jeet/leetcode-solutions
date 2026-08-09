/*
 * LeetCode: 930 - Binary Subarrays With Sum
 * Link: https://leetcode.com/problems/binary-subarrays-with-sum/
 * Difficulty: Medium
 * Time: O(n) for the sliding window approach
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        if(goal==0){
            int count=0;
            for(int el:nums){
                if(el==0) count++;
                else count=0;
                ans+=count;
            }
        }else{
            unordered_map<int,int> u_map;
            int sum=0;
            u_map[0]++;
            for(int el:nums){
                sum+=el;
                u_map[sum]++;
                if(u_map.count(sum-goal)!=0) ans+=u_map[sum-goal];
            }
        }
        return ans;
    }
};