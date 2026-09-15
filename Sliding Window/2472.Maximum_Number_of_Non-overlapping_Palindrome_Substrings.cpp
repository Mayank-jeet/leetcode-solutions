/*
 * LeetCode: 2472 - Maximum Number of Non-overlapping Palindrome Substrings
 * Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
 * Difficulty: Hard
 * Time: O(n^2) in worst case, where n is the length of the input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.length(),end=-1;
        int ans=0;
        int max=n-(k-1)/2;
        for(int i=0;i<max;i++){
            for(int l:{i-1,i}){
                int r=i;
                while(l>=0 && r<n && s[l]==s[r] && l>end){
                    if(r-l+1>=k){
                        ans++;
                        end=r;
                        break;
                    }
                    l--;r++;
                }

            }
        }
        return ans;
    }
};