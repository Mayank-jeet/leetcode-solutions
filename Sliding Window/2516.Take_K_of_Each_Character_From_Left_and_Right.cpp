/*
 * LeetCode: 2516 - Take K of Each Character From Left and Right
 * Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
 * Difficulty: Medium
 * Time: O(n) where n is the length of input string
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(s.length()<3*k) return -1;
        int a=0,b=0,c=0;
        int n=s.length(),i=0;
        while((a<k || b<k || c<k) && i<n){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
            i++;
        }
        if(a<k || b<k || c<k) return -1;
        int ans=a+b+c;
        int last=ans-1,back=n-1;
        while(last>=0){
            if(s[back]=='a') a++;
            else if(s[back]=='b') b++;
            else c++;
            while(last>=0){
                if(s[last]=='a') {
                    if(a<=k) break;
                    a--;
                }
                else if(s[last]=='b') {
                    if(b<=k) break;
                    b--;
                }
                else {
                    if(c<=k) break;
                    c--;
                }
                last--;
            }
            ans=min(ans,a+b+c);
            back--;
        }
        return ans;
    }
};