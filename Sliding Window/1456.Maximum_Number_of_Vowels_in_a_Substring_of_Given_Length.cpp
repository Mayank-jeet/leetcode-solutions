/*
 * LeetCode: 1456 - Maximum Number of Vowels in a Substring of Given Length
 * Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length(),back_v=0,ans=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') ans++;
        }
        int total_v=ans;
        for(int i=k;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                total_v++;
            }
            if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u'){
                back_v++;
            }
            ans=max(total_v-back_v,ans);
        }
        return ans;
    }
};