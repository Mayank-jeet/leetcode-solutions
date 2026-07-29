/*
 * LeetCode: 825 - Friends Of Appropriate Ages
 * Link: https://leetcode.com/problems/friends-of-appropriate-ages/
 * Difficulty: Medium
 * Time: O(n log n), where n is the size if vector ages
 * Space: O(1) auxiliary
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int left=0,n=ages.size(),ans=0,count=0;
        for(int i=1;i<n;i++){
            int limit=(ages[i]/2)+7;
            while(left<i && ages[left]<=limit) left++;
            if(ages[i]==ages[i-1] && ages[i]>limit) count++;
            else count=0;
            ans+=(i-left+count);
        }
        return ans;
    }
};