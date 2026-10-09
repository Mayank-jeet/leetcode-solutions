/*
 * LeetCode: 1541 - Minimum_Insertions_to_Balance_a_Parentheses_String
 * Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
 * Difficulty: Medium
 * Time: O(n) where n is length of input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int sum=0;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') sum++;
            else{
                if(i==n-1 || s[i+1]!=')'){
                    ans++;
                }
                else i++;
                sum--;
                if(sum<0){
                    ans+=abs(sum);
                    sum=0;
                }
            }
        }
        return ans+sum*2;
    }
};