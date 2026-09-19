/*
 * LeetCode: 1015 - Smallest Integer Divisible by K
 * Link: https://leetcode.com/problems/smallest-integer-divisible-by-k/
 * Difficulty: Medium
 * Time: O(k)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1) return 1;
        if(k%2==0 || k%5==0) return -1;
        int rem=0;
        for(int i=1;i<=k;i++){
            rem=(rem*10+1)%k;
            if(rem==0) return i;
        }
        return -1;
    }
};