/*
 * LeetCode: 1525 - Number of Good Ways to Split a String
 * Link: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
 * Difficulty: Medium
 * Time: O(n) where n is the size of input string
 * Space: O(1), as unordered_map will store maximum 26 different letters of alphabets, i.e. O(26), constant space
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSplits(string s) {
        unordered_map<int,int> u_map1;
        int n=s.length();
        for(int i=0;i<n;i++) u_map1[s[i]]++;
        unordered_map<int,int> u_map2;
        int rightLen=u_map1.size(),ans=0;
        for(int i=0;i<n;i++){
            u_map2[s[i]]++;
            u_map1[s[i]]--;
            if(u_map1[s[i]]==0) rightLen--;
            if(u_map2.size()>rightLen) break;
            else if(u_map2.size()==rightLen) ans++;
        }
        return ans;
    }
};