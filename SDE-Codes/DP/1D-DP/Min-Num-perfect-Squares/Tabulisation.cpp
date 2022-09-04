#include<iostream>
#include<vector>
using namespace std;
int solve(int n){
	    //base case
	    
	    vector<int> dp(n+1,INT_MAX);
	    
	    dp[0]=0;
	    
	    
	    for(int i =1;i<=n;i++){
	        int ans=i;
	        for(int j=1;j*j<=n;j++){
	            int temp=j*j;
	            if(i-temp >=0){
	                dp[i]=min(dp[i],1+dp[i-temp]);
	            }
	        }
	    }
	    
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    return solve(n);
	}
	