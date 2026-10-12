/*
 * LeetCode: 2897 - Apply Operations on Array to Maximize Sum of Squares
 * Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/
 * Difficulty: Hard
 * Time: O(30(n+k)) where n is the size of nums and k is the number of operations
 * Space: O(30) for bits vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(30,0);
        for(int x:nums){
            for(int i=0;i<30;i++){
                if(x&(1<<i)) bits[i]++;
            }
        }
        long long ans=0;
        const long long MOD=1000000007;
        for(int i=0;i<k;i++){
            long long el=0;
            for(int j=29;j>=0;j--){
                if(bits[j]>0){
                    el|=(1LL<<j);
                    bits[j]--;
                }
            }
            ans=(ans+el*el)%MOD;
        }
        return ans;
    }
};