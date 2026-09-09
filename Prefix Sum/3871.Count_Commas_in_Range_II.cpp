/*
 * LeetCode: 3871 - Count Commas in Range II
 * Link: https://leetcode.com/problems/count-commas-in-range-ii/
 * Difficulty: Medium
 * Time: O(d) where d is the number of degits in n
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000000) return max((int)n-999,0);
        long long ans=0;
        long long temp=n;
        int count=0,commas=0;
        long long lastCount=1,currentCount=1000;
        while(temp>0){
            count++;
            if(count>1 && (count-1)%3==0){
                if(count>6){
                    lastCount*=1000;
                    currentCount*=1000;
                    ans+=commas*(currentCount-lastCount);
                }
                commas++;
                if(temp<1000) break;
            }
            temp/=10;
        }
        ans+=commas*(n-currentCount+1);
        return ans;
    }
};