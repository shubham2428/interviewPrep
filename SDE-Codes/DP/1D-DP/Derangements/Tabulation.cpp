#define MOD 1000000007
#include<vector>
#include<iostream>
using namespace std;




long long int solve(int n){
    
    // step1: creating a dp array
    vector<long long int> dp(n+1,0);
    
    // analylising the base case;
    dp[1]=0;
    dp[2]=1;
    
    // iterate into the dp array
    
    for(int i =3;i<=n;i++){
        long long int first=dp[i-1]%MOD;
        
        long long int second=dp[i-2]%MOD;
        
        long long int sum=(first+second)%MOD;
        
        long long int ans = ((i-1)* sum)%MOD;
        
        dp[i]=ans;
    }
    
    return dp[n];
}
long long int countDerangements(int n) {
 
    return solve(n);
    
}