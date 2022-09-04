#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int> &nums,int index,vector<int> &dp){
   if(index<0){
        return 0;
    }
    
    if(index==0){
        return nums[0];
    }
    
    // fetching the result if already present
    if(dp[index]!=-1){
        return dp[index];
    }
    int include=solve(nums,index-2,dp) + nums[index];
    int exclude=solve(nums,index-1,dp) + 0;
    
    // storing the ans in dp array
    dp[index]=max(include,exclude);
    return dp[index];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int index=nums.size()-1;
    int n=nums.size();
    //step1 creating dp array 
    vector<int> dp(n+1,-1);
    return solve(nums,index,dp);
}