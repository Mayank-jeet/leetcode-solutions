/*
 * LeetCode:274 - H-Index
 * Link: https://leetcode.com/problems/h-index/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int> ());
        int n=citations.size(),ans=0;
        for(int i=0;i<n;i++){
            if(citations[i]>=i+1){
                ans++;
            }else break;
        }
        return ans;
    }
};