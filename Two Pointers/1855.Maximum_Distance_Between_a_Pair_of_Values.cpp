/*
 * LeetCode: 1855 - Maximum Distance Between a Pair of Values
 * Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
 * Difficulty: Medium
 * Time: O(n*m)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& arr,int high,int low,int max){
        while(low<=high && high!=-1){
            int mid=low+(high-low)/2;
            if(arr[mid]>max) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int prev=0,n=nums2.size(),m=nums1.size(),ans=0;
        for(int i=0;i<n;i++){
            if(prev>=m) break;
            if(nums2[i]>=nums1[prev] | nums2[i]>=nums1[std::min(i,(int)nums1.size()-1)]){
                prev=search(nums1,std::min(i,(int)nums1.size()-1),prev,nums2[i]);
                ans=max(ans,i-prev);
            }else prev=i;
        }
        return ans;
    }
};