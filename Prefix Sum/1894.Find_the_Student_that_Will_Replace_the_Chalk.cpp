/*
 * LeetCode: 1894 - Find the Student that Will Replace the Chalk
 * Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        vector <long long> temp;
        long long sum=0;
        for(int el:chalk){
            sum+=(long long)el;
            temp.emplace_back(sum);
        }
        long long back=temp.back();
        int laps=k/back;
        k-=(laps*back);
        int low=0,high=temp.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(temp[mid]>k) high=mid;
            else low=mid+1;
        }
        return low;
    }
};