#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &nums,int index){

    int n=nums.size();
    vector<int> dp(n+1,0);
    
    dp[0]=nums[0];
    
    for(int i=1;i<n;i++){
        int inclusive=dp[i-2]+nums[i];
        int exclusion=dp[i-1]+0;
        dp[i]=max(inclusive,exclusion);
    }
    
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int index=nums.size()-1;
    int n=nums.size();
    
    return solve(nums,index);
}