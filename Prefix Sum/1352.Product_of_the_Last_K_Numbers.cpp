/*
 * LeetCode: 1352 - Product of the Last K Numbers
 * Link: https://leetcode.com/problems/product-of-the-last-k-numbers/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
public:
    int nearestZero=INT_MIN;
    int prod=1;
    vector<int> products;
    ProductOfNumbers() {
        
    }

    void add(int num) {
        prod*=num;
        products.push_back(prod);
        if(num==0) {
            prod=1;
            nearestZero=products.size()-1;
        }
    }
    
    int getProduct(int k) {
        int n=products.size();
        if(n-k<=nearestZero) return 0;
        else if(n==k || products[n-1-k]==0) return prod;
        return prod/products[n-1-k];
    }
};