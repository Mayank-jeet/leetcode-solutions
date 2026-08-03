/*
 * LeetCode: 1248 - Count Number of Nice Subarrays
 * Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) space used for unordered_map
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k){ 
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0,ans=0;
        for(int el:nums){
            if(el%2!=0){
                sum++;
            }
            map[sum]++;
            if(map.count(sum-k)!=0) ans+=map[sum-k];
        }
        return ans;
    }
};