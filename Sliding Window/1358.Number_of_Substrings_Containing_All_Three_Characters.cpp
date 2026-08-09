/*
 * LeetCode: 1358. Number of Substrings Containing All Three Characters
 * Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1,n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else if(s[i]=='c') c=i;
            if(a!=-1 && b!=-1 && c!=-1){
                ans=ans+1+min({a,b,c});
            }
        }
        return ans;
    }
};