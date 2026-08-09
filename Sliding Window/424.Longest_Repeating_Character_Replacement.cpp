/*
 * LeetCode: 424 - Longest Repeating Character Replacement
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(26) for storing the frequency of characters in the string
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        int left=0,n=s.length(),max_freq=0;
        vector<int> vec(26,0);
        for(int i=0;i<n;i++){
            vec[s[i]-'A']++;
            max_freq=max(max_freq,vec[s[i]-'A']);
            if((i+1-left-max_freq)>k){
                while((i+1-left-max_freq)>k){
                    vec[s[left]-'A']--;
                    left++;
                }
            }
            ans=max(ans,i+1-left);
        }
        return ans;
    }
};