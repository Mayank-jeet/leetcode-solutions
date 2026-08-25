/*
 * LeetCode: 1750 - Minimum Length of String After Deleting Similar Ends
 * Link: https://leetcode.com/minimum-number-of-vertices-to-reach-all-nodes/
 * Difficulty: Medium
 * Time: O(n) where n is length of input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int left=0,right=n-1;
        int lastDel=-1;
        while(left<right && left<n && right>=0 && s[left]==s[right]){
            while(left+1<n && s[left]==s[left+1] && left<right) {
                lastDel=left;
                left++;
            }
            while(right-1>=0 && s[right]==s[right-1] && left<right) right--;
            if(left==right) if(lastDel<left) return 0;
            if(left!=right){
                left++;
                right--;
            }
        }
        return right-left+1;
    }
};