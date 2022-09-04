#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    
    int solve(vector<int>& cost,int n){
        vector<int> dp(n+1);  // creating dp array  step 1
        

        // visulising base case and added accordingly
        dp[0]=cost[0];
        dp[1]=cost[1];

        // finding the answer in dp array
        
        for(int i =2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=solve(cost,n);
        return ans;
        
    }
};