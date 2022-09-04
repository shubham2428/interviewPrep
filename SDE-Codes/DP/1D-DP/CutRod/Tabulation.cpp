#include<iostream>
#include<vector>
using namespace  std;
#include<limits.h>

int solve(int n,int x, int y, int z){
    //ste1 creating dp array
    vector<int> dp(n+1,INT_MIN);
   
    
    //step2 visulising base case
    dp[0]=0;
    
    // step 3 iterate over dp array
   for(int i=1;i<=n;i++){
       if(i-x>=0){
            dp[i]=max(dp[i],dp[i-x]+1);
       }
        if(i-y>=0){
            dp[i]=max(dp[i],dp[i-y]+1);
       }
        if(i-z>=0){
            dp[i]=max(dp[i],dp[i-z]+1);
       }
        
   }
    if(dp[n]<0){
        return 0;
    }
    else{
        return dp[n];
    }
}


int cutSegments(int n, int x, int y, int z) {
    
    return solve(n,x,y,z);
    
    
   
}