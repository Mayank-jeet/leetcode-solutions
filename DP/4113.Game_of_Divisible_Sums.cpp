/*
 * LeetCode: 4113 - Game of Divisible Sums
 * Link: https://leetcode.com/problems/game-of-divisible-sums/
 * Difficulty: Hard
 * Time: O(n) where n is the length of the array
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> leading(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long occupied=0;
            leading[i]=LONG_MIN;
            for(int j=1;j<=2 && i+j<=n;j++){
                occupied+=nums[i+j-1];
                long long rest=leading[i+j];
                long long gain=occupied%3==0?occupied-rest:occupied+rest;
                leading[i]=max(leading[i],gain);
            }
        }
        return leading[0];
    }
};