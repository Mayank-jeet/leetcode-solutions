/*
 * LeetCode: 4071 - Minimum Rotations to Dial a Number II
 * Link: https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/
 * Difficulty: Medium
 * Time: O(n) where n is length of input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRotations(int n, string s) {
        int ans=0;
        int curr=0;
        for(char el:s){
            int currentEl=el-'0';
            ans+=min(abs(currentEl-curr),10-abs(currentEl-curr));
            curr=currentEl;
        }
        int tempAns=ans;
        int lastEl=s[n-1]-'0';
        int first=s[0]-'0';
        ans=min(ans,tempAns-min(first,10-first)+min(lastEl,10-lastEl));
        for(int i=n-2;i>=0;i--){
            int currentEl=s[i+1]-'0';
            int src=s[i]-'0';
            tempAns-=min(abs(currentEl-src),10-abs(currentEl-src));
            tempAns+=min(abs(lastEl-src),10-abs(lastEl-src));
            ans=min(ans,tempAns);
            tempAns-=min(abs(lastEl-src),10-abs(lastEl-src));
            tempAns+=min(abs(currentEl-src),10-abs(currentEl-src));
        }
        return ans;
    }
};