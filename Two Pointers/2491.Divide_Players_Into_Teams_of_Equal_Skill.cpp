/*
 * LeetCode: 2491 - Divide Players Into Teams of Equal Skill
 * Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
 * Difficulty: Medium
 * Time: O(nlogn) for sorting + O(n) for matching 
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int sum=skill[0]+skill[n-1];
        long long ans=0;
        for(int i=0;i<n/2;i++){
            if((skill[i]+skill[n-1-i])!=sum) return -1;
            ans+=(skill[i]*skill[n-1-i]);
        }
        return ans;
    }
};