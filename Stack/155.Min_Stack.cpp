/*
 * LeetCode: 155 - Min Stack
 * Link: https://leetcode.com/problems/min-stack/
 * Difficulty: Easy
 * Time: O(1) for all operations
 * Space: O(n) for the two stacks
 */
#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<int>s,minStack;
    MinStack(){
        
    }
    
    void push(int val) {
        s.push(val);
        if(minStack.empty() || val<minStack.top()){
            minStack.push(val);
        }else{
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        minStack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};