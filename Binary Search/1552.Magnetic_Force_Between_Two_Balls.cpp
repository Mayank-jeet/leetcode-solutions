/*
 * LeetCode: 1552 - Magnetic Force Between Two Balls
 * Link: https://leetcode.com/problems/magnetic-force-between-two-balls/
 * Difficulty: Medium
 * Time: O(nlog(m)) where n is the number of elements in the array and m is the maximum element in the array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& position, int m,int minDist){
        int n=position.size(),lastIndex=0,count=0;
        for(int i=1;i<n;i++){
            if(position[i]-position[lastIndex]>=minDist){
                count++;
                lastIndex=i;
            }
            if(count>=m && (position[n-1]-position[lastIndex])>=minDist) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        if(m==2) return position[position.size()-1]-position[0];
        int low=1,high=((position[position.size()-1]-1)-(position[0]+1))/(m-2);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(position,m-2,mid)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};