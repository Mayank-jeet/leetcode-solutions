/*
 * LeetCode: 729 - My Calendar I
 * Link: https://leetcode.com/problems/my-calendar-i/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class MyCalendar {
public:
    vector<pair<int,int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        sort(bookings.begin(),bookings.end());
        if(bookings.size()==0 || bookings[0].first>=endTime || bookings[bookings.size()-1].second<=startTime){
            bookings.emplace_back(startTime,endTime);
            return true;
        }
        int low=0,high=bookings.size()-1,n=bookings.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bookings[mid].second<=startTime){
                if(mid<(n-1) && bookings[mid+1].first>=startTime){
                    if(bookings[mid+1].first==startTime || bookings[mid+1].first<endTime) return false;
                    else{
                        bookings.emplace_back(startTime,endTime);
                        return true;
                    }
                }else low=mid+1;
            }else high=mid-1;
        }
        return false;
    }
};