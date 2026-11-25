/*
 * LeetCode: 3934 - Smallest Unique Subarray
 * Link: https://leetcode.com/problems/smallest-unique-subarray/
 * Difficulty: Hard
 * Time: O(nlog²n) where n is the length of nums
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        long long M1=1000000007,M2=998244353,B=100003;
        vector<long long> p1(n+1,0),p2(n+1,0),w1(n+1,1),w2(n+1,1);
        for(int i=0;i<n;i++){
            p1[i+1]=(p1[i]*B+nums[i])%M1;
            p2[i+1]=(p2[i]*B+nums[i])%M2;
            w1[i+1]=w1[i]*B%M1;
            w2[i+1]=w2[i]*B%M2;
        }
        auto found=[&](int len){
            vector<long long> v;
            for(int i=0;i+len<=n;i++){
                long long h1=((p1[i+len]-p1[i]*w1[len])%M1+M1)%M1;
                long long h2=((p2[i+len]-p2[i]*w2[len])%M2+M2)%M2;
                v.push_back(h1*M2+h2);
            }
            sort(v.begin(),v.end());
            int m=v.size();
            for(int i=0;i<m;i++){
                bool sameLeft=i>0&&v[i]==v[i-1];
                bool sameRight=i+1<m&&v[i]==v[i+1];
                if(!sameLeft&&!sameRight)return true;
            }
            return false;
        };
        int lo=1,hi=n;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(found(mid))hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};