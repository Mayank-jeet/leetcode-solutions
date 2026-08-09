/*
 * LeetCode:  622 - Design Circular Queue
 * Link: https://leetcode.com/problems/design-circular-queue/
 * Difficulty: Medium
 * Time: O(1) for all operations
 * Space: O(n) where n is the number elements in the queue
 */
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int data):val(data),next(nullptr){}
};
class MyCircularQueue {
public:
    int filled=0;
    Node* head=nullptr;
    Node* tail=nullptr;
    int maxSize;
    MyCircularQueue(int k):maxSize(k) {
        
    }
    
    bool enQueue(int value) {
        if(filled==maxSize) return false;
        Node* newNode=new Node(value);
        if(!head){
            head=newNode;
            tail=head;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
        filled++;
        return true;
    }
    
    bool deQueue() {
        if(filled==0) return false;
        Node* tempNode=head->next;
        head->next=nullptr;
        head=tempNode;
        filled--;
        return true;
    }
    
    int Front() {
        if(filled==0) return -1;
        else return head->val;
    }
    
    int Rear() {
        if(filled==0) return -1;
        else return tail->val;
    }
    
    bool isEmpty() {
        return filled==0;
    }
    
    bool isFull() {
        return filled==maxSize;
    }
};