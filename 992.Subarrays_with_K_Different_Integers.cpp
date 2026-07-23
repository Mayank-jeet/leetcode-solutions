/*
 * LeetCode: 992 - Subarrays with K Different Integers
 * Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
 * Difficulty: Hard
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int low=0,high=0,count=0,ans=0,n=nums.size();
        unordered_map<int,int> u_map;
        for(int i=0;i<n;i++){
            u_map[nums[i]]++;
            if(u_map[nums[i]]==1) count++;
            while(count>k && high<=i){
                u_map[nums[high]]--;
                if(u_map[nums[high]]==0) count--;
                high++;
                low=high;
            }
            while(count==k && high<=i){
                if(u_map[nums[high]]==1) break;
                u_map[nums[high]]--;
                high++;
            }
            if(count==k) ans+=(high-low+1);
        }
        return ans;
    }
};
