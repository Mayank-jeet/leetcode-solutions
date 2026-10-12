/*
 * LeetCode: 4079 - Prime Subset Selection I
 * Link: https://leetcode.com/problems/prime-subset-selection-i/
 * Difficulty: Medium
 * Time: O(n√n)
 * Space: O(k) for ans, where k is the number of primes picked
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrime(int n) {
        if (n<2) return false;
        if (n<4) return true;
        if (n%2==0 || n%3==0) return false;
        for (long long i=5;i*i<=n;i+= 6)
            if (n%i==0 || n%(i+2)==0) return false;
        return true;
    }
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        long long sum=0;
        for(int i=1;i<=n && sum+i<=s;++i){
            if(isPrime(i)){
                sum+=i;
                ans.push_back(i);
            }
        }
        return ans;
    }
};