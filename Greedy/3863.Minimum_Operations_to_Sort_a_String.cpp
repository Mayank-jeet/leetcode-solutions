/*
 * LeetCode: 3863 - Minimum Operations to Sort a String
 * Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        if(s.length()==1) return 0;
        else if(s.length()==2){
            if(s[1]<s[0]) return -1;
            else return 0;
        }
        char minChar='z',maxChar='a';
        int n=s.length();
        bool needSorting=false;
        int maxCharCount=1,minCharCount=1;
        for(int i=0;i<n;i++){
            if(i!=n-1 && s[i]>s[i+1]) needSorting=true;
            if(s[i]<minChar){
                minChar=s[i];
                minCharCount=1;
            }
            else if(s[i]==minChar) minCharCount++;
            if(s[i]>maxChar){
                maxChar=s[i];
                maxCharCount=1;
            }
            else if(s[i]==maxChar) maxCharCount++;
        }
        if(needSorting){
            if(s[0]==minChar || s[n-1]==maxChar) return 1;
            else if(s[0]==maxChar && s[n-1]==minChar && maxCharCount==1 && minCharCount==1) return 3;
            else return 2;
        }
        return 0;
    }
};