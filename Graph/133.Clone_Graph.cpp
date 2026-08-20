/*
 * LeetCode: 133 - Clone Graph
 * Link: https://leetcode.com/problems/clone-graph/
 * Difficulty: Medium
 * Time: O(V+E)
 * Space: O(V+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<Node*, Node*> visited;
    void createNode(vector<Node*>& neighbors,vector<Node*>& node){
        for(int i=0;i<node.size();i++){
            if(visited.count(node[i])) {
                neighbors.push_back(visited[node[i]]);
                continue;
            }
            Node* root=new Node(node[i]->val);
            visited[node[i]]=root;
            neighbors.push_back(root);
            createNode(root->neighbors,node[i]->neighbors);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(visited.count(node)) return visited[node];
        Node* root=new Node(node->val);
        visited[node]=root;
        createNode(root->neighbors,node->neighbors);
        return root;
    }
};