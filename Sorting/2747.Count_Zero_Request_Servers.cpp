/*
 * LeetCode: 2747 - Count Zero Request Servers
 * Link: https://leetcode.com/problems/count-zero-request-servers/
 * Difficulty: Medium
 * Time: Time: O(LlogL+QlogQ+L+Q) where L is number of logs, Q is number of queries, n is number of servers
 * Space: O(n+Q) where n is freq array, Q is qs array and ans array
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    vector<int> countServers(int n,vector<vector<int>>&logs,int x,vector<int>&queries){
        int q=queries.size();
        int l=logs.size();
        sort(logs.begin(),logs.end(),cmp);
        vector<pair<int,int>> qs;
        for(int i=0;i<q;i++) qs.push_back({queries[i],i});
        sort(qs.begin(),qs.end());
        vector<int> ans(q,0);
        vector<int> freq(n+1,0);
        int active=0;
        int i=0,j=0;
        for(int k=0;k<q;k++){
            int time=qs[k].first;
            int idx=qs[k].second;
            int start=time-x;
            int end=time;
            while(j<l&&logs[j][1]<=end){
                int id=logs[j][0];
                freq[id]++;
                if(freq[id]==1)active++;
                j++;
            }
            while(i<l&&logs[i][1]<start){
                int id=logs[i][0];
                freq[id]--;
                if(freq[id]==0)active--;
                i++;
            }
            ans[idx]=n-active;
        }
        return ans;
    }
};