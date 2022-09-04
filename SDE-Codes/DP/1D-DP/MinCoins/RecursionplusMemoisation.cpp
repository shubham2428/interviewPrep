#include<iostream>
#include<vector>
using namespace std;

int solveRecplusMemo(vector<int> &num,int x,vector<int>& dp){
    if(x==0){
        return x;
    }
    if(x<0){
        return INT_MAX;
    }
    
    // step 3  checking ans is already existing or not
    if(dp[x]!=-1){
        return dp[x];
    }

    int mini=INT_MAX;
    
    for(int i =0;i<num.size();i++){
        int ans=solveRecplusMemo(num,x-num[i],dp);
        
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    
    //step 2: storing ans in dp array
    
    dp[x]=mini;
    
    return mini;
}



int minimumElements(vector<int> &num, int x)
{
    
    //step1 creating dp array of size x+1;
    
    vector<int> dp(x+1,-1);
    int ans=solveRecplusMemo(num,x,dp);
    if(ans==INT_MAX){
        return -1;
    }
    else{
        return ans;
    }
}