 /*
 * LeetCode: 1401 - Circle and Rectangle Overlapping
 * Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/
 * Difficulty: Medium
 * Time: O(1)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x=clamp(xCenter,x1,x2)-xCenter;
        int y=clamp(yCenter,y1,y2)-yCenter;
        return x*x+y*y<=radius*radius;
    }
};