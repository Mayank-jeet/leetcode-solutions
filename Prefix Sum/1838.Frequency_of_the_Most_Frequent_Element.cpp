/*
 * LeetCode: 1838 - Frequency of the Most Frequent Element
 * Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
 * Difficulty: Medium
 * Time: O(nlog(n)) for sorting the input vector, O(n) for traversing the input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1,n=nums.size();
        int left=0;
        long long diff=0;
        for(int i=1;i<n;i++){
            int el=i-left;
            diff+=(long long)(nums[i]-nums[i-1])*el;
            if(diff>k){
                while(diff>k && left<=i) {
                    diff-=(nums[i]-nums[left]);
                    left++;
                }
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};