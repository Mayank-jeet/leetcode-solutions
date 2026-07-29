/*
 * LeetCode: 881 - Boats to Save People
 * Link: https://leetcode.com/problems/boats-to-save-people/
 * Difficulty: Medium
 * Time: O(n log n), where n is the size of vector people
 * Space: O(1) auxiliary
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0;
        int first=0,last=people.size()-1;
        while(first<last){
            if((people[first]+people[last])<=limit){
                ans++;
                first++;
                last--;
            }
            else{
                ans++;
                last--;
            }
        }
        if(first==last) ans++;
        return ans;
    }
};