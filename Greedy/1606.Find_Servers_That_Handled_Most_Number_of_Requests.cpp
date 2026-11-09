/*
 * LeetCode: 1606 - Find Servers That Handled Most Number of Requests
 * Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
 * Difficulty: Medium
 * Time: O(nlogk) where n is the length of input vector and k is the number of servers
 * Space: O(k)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> busiestServers(int k,vector<int>& arrival,vector<int>& load) {
        vector<int> handle(k,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> free;
        for(int i=0;i<k;i++) free.insert(i);
        int n=arrival.size();
        for(int i=0;i<n;i++){
            while(!pq.empty()){
                auto [time,node]=pq.top();
                if(time<=arrival[i]){
                    pq.pop();
                    free.insert(node);
                }
                else break;
            }
            if(free.empty()) continue;
            auto it=free.lower_bound(i%k);
            if(it==free.end()) it=free.begin();
            int node=*it;
            free.erase(it);
            pq.push({arrival[i]+load[i],node});
            handle[node]++;
        }
        int maxLoad=*max_element(handle.begin(),handle.end());
        vector<int> res;
        for(int i=0;i<k;i++){
            if(handle[i]==maxLoad) res.push_back(i);
        }
        return res;
    }
};