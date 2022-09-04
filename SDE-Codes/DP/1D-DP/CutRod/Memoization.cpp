#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int solve(int n,int x, int y, int z,vector<int> &dp ){
    //base case
    
    if(n==0){
        return 0;
    }
    
    if(n<0){
        return INT_MIN;
    }
    //step 3 if result already present take from that array
    
    if(dp[n]!=-1){
        return dp[n];
    }
    int a=solve(n-x,x,y,z,dp) + 1;
    int b=solve(n-y,x,y,z,dp) + 1;
    int c=solve(n-z,x,y,z,dp) + 1;
    
    //step2 store in dp array
    
    dp[n]= max(a,max(b,c));
    return dp[n];
}


int cutSegments(int n, int x, int y, int z) {
    //step 1 creating dp of size n+1
    
   vector<int> dp(n+1,-1);
    
	int ans=solve(n,x,y,z,dp);
    
    
    if(ans<0){
        return 0;
    }
    else{
        return ans;
    }
}