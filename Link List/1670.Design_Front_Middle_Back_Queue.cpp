/*
 * LeetCode:  1670 - Design Front Middle Back Queue
 * Link: https://leetcode.com/problems/design-front-middle-back-queue/
 * Difficulty: Medium
 * Time: O(1) for all operations except pushMiddle and popMiddle which are O(n/2) or O(n) where n is the number of nodes in the list
 * Space: O(n) where n is the number of nodes in the list
 */
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int data):val(data),next(nullptr),prev(nullptr){}
};
class FrontMiddleBackQueue {
public:
    Node* head;
    Node* tail;
    FrontMiddleBackQueue():head(nullptr),tail(nullptr) {
        
    }
    
    void pushFront(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        if(!head) tail=newNode;
        else  head->prev=newNode;
        head=newNode;
    }
    
    void pushMiddle(int val) {
        Node* newNode=new Node(val);
        Node* tempHead=head;
        Node* tempTail=tail;
        while(tempHead!=tempTail && tempHead->next!=tempTail->prev && tempHead->next!=tempTail){
            tempHead=tempHead->next;
            tempTail=tempTail->prev;
        }
        if(tempHead==tempTail){
            newNode->next=tempHead;
            if(!tempHead) tail=newNode;
            else tempHead->prev=newNode;
            head=newNode;
        }
        else{
            newNode->next=tempHead->next;
            tempHead->next->prev=newNode;
            tempHead->next=newNode;
            newNode->prev=tempHead;
        }
    }
    
    void pushBack(int val) {
        Node* newNode=new Node(val);
        if(!head){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    
    int popFront() {
        if(!head) return -1;
        Node* delNode=head;
        head=head->next;
        if(!head) tail=nullptr;
        else head->prev=nullptr;
        delNode->next=nullptr;
        return delNode->val;
    }
    
    int popMiddle() {
        if(!head) return -1;
        Node* tempHead=head;
        Node* tempTail=tail;
        while(tempHead!=tempTail && tempHead->next!=tempTail->prev && tempHead->next!=tempTail){
            tempHead=tempHead->next;
            tempTail=tempTail->prev;
        }
        if(tempHead==tempTail) return popFront();
        else if(tempHead->next==tempTail){
            Node* delNode=tempHead;
            if(delNode==head) return popFront();
            else{
                tempHead->prev->next=tempTail;
                tempTail->prev=tempHead->prev;
                delNode->next=nullptr;
                delNode->prev=nullptr;
                return delNode->val;
            }
        }
        else{
            Node* delNode=tempHead->next;
            tempHead->next=tempTail;
            tempTail->prev=tempHead;
            delNode->prev=nullptr;
            delNode->next=nullptr;
            return delNode->val;
        }
    }
    
    int popBack() {
        if(!head) return -1;
        Node* delNode=tail;
        tail=tail->prev;
        if(!tail) head=nullptr;
        else tail->next=nullptr;
        delNode->prev=nullptr;
        return delNode->val;
    }
};