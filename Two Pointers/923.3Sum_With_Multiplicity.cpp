/*
 * LeetCode: 923 - 3Sum With Multiplicity
 * Link: https://leetcode.com/problems/3sum-with-multiplicity/
 * Difficulty: Medium
 * Time: O(nlog(n)) for sorting + O(n^2) for loop
 * Space: O(1)
 */
// This solutution can be simplified more, using map, but that will take more space O(n) in worst case
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        long long ans=0;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>target) k--;
                else if(sum<target) j++;
                else if(arr[j]!=arr[k]){
                    int left=arr[j],right=arr[k];
                    int lc=1,rc=1;
                    while (j+1<k && arr[j+1]==left)  {j++; lc++;}
                    while (k-1>j && arr[k-1]==right) {k--; rc++;}
                    ans+=(long long)lc*rc;
                    ans%=1000000007;
                    j++; 
                    k--;
                }else{
                    long long count=k-j + 1;
                    ans+=count*(count-1)/2;
                    ans%=1000000007;
                    break;
                }
            }
        }
        return (int)ans;
    }
};