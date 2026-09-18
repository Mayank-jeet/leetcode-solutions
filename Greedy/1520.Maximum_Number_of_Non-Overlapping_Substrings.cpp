/*
 * LeetCode: 1520 - Maximum Number of Non-Overlapping Substrings
 * Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
 * Difficulty: Medium
 * Time: O(n) where n is length of input string
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<string> ans;
        int n=s.length();
        unordered_map<char,pair<int,pair<int,int>>> u_map;
        for(int i=0;i<n;i++){
            u_map[s[i]].first++;
            if(u_map[s[i]].first==1) u_map[s[i]].second.first=i;
            u_map[s[i]].second.second=i;
        }
        vector<pair<int,int>> intervals;
        for(char c='a';c<='z';c++){
            if(u_map.find(c)==u_map.end())
                continue;
            int startIndex=u_map[c].second.first;
            int endIndex=u_map[c].second.second;
            bool valid=true;
            for(int i=startIndex;i<=endIndex;i++){
                char x=s[i];
                if(u_map[x].second.first<startIndex){
                    valid=false;
                    break;
                }
                endIndex=max(endIndex,u_map[x].second.second);
            }
            if(valid)
                intervals.push_back({startIndex,endIndex});
        }
        sort(intervals.begin(),intervals.end(),
            [](pair<int,int> a,pair<int,int> b){
                return a.second<b.second;
            });
        int prevIndex=-1;
        for(auto interval:intervals){
            int startIndex=interval.first;
            int endIndex=interval.second;
            if(startIndex>prevIndex){
                ans.push_back(s.substr(startIndex,endIndex-startIndex+1));
                prevIndex=endIndex;
            }
        }
        return ans;
    }
};