/*
 * LeetCode: 187 - Repeated DNA Sequences
 * Link: https://leetcode.com/problems/repeated-dna-sequences/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length()<10) return ans;
        unordered_map<string,int> u_map;
        for(int i=0;i<=s.length()-10;i++){
            string sub=s.substr(i,10);
            u_map[sub]+=1;
            if(u_map.find(sub)!=u_map.end() && u_map[sub]==2) ans.push_back(sub);
        }
        return ans;
    }
};