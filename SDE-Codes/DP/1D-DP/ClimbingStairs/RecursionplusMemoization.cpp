#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    
    int solve(vector<int>& cost,int n,vector<int>& dp){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        
        //step3: check if ans is already present return from here, no need to go for next calls
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        // step 2: store the ans in dp array
        dp[n]= cost[n]+ min(solve(cost,n-1,dp) , solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        
        // step1 : created a dp array of size n+1;
        vector<int> dp(n+1,-1);
        
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
        
    }
};