/*
 * LeetCode: 1297 - Maximum Number of Occurrences of a Substring
 * Link: https://leetcode.com/maximum-number-of-occurrences-of-a-substring/
 * Difficulty: Medium
 * Time: O(n) where n is size of input vector
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> substr_freq;
        unordered_map<char,int> letter_freq;
        int low=0,unique_letter_count=0;
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            letter_freq[s[i]]++;
            if(letter_freq[s[i]]==1) unique_letter_count++;
            if(i-low+1>minSize){
                letter_freq[s[low]]--;
                if(letter_freq[s[low]]==0) unique_letter_count--;
                low++;
            }
            if(i-low+1==minSize && unique_letter_count<=maxLetters){
                string sub_string=s.substr(low,i-low+1);
                substr_freq[sub_string]++;
                ans=max(ans,substr_freq[sub_string]);
            }
        }
        return ans;
    }
};