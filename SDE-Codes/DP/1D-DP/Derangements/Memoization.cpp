#define MOD 1000000007
#include<vector>
#include<iostream>
using namespace std;


long long int solve(int n , vector<long long int> &dp){
    
    if(n==1){
        return 0;
    }// if n is 1 dearrangments possible he nhi hain
        
    if(n==2){
        return 1;  // agr sirf 2 elements hain eska matlab 1 he dearrangment possible hain
    }
     
    
    // step 3: check if ns is already present
    if(dp[n]!=-1){
        return dp[n];
    }
     
    // step 2: storing ans in dp array
    dp[n] =  ( ((n-1)% MOD) *( (solve(n-1,dp)%MOD)
                                 + (solve(n-2,dp)%MOD))%MOD);
                              
    return dp[n];             
    
}
long long int countDerangements(int n) {
    // step 1 : creating an dp array
    vector<long long int> dp(n+1,-1);
    return solve(n,dp);
    
}