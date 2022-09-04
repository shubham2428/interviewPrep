#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int> &dp){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    
	    
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int ans=n; // kyuki maximum toh 1ke square se bn kste hain and vo n ke equal he honge
	    
	    for(int i =1;i*i<=n;i++){
	        int temp=i*i;
	        ans=min(ans,1+solve(n-temp,dp));  // hm one esme esliye jodte hain kyuki jo number use ho rha h vo bhi add krna h 
	        
	    }
	    dp[n]=ans;
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    // step1
	    vector<int> dp(n+1,-1);
	    return solve(n,dp);
	}
	