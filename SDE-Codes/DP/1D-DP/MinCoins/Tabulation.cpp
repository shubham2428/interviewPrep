#include<iostream>
#include<vector>
using namespace std;

int solveTab(vector<int> &num, int x){
    vector<int> dp(x+1,INT_MAX);
    
    dp[0]=0;
    
    for(int i =1;i<=x;i++){
        //checking for every coin
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]] !=INT_MAX) // to undersatnd this check Memo code and came step by step
            dp[i]=min(dp[i],1+dp[i-num[j]]);
        }
    }
    if(dp[x]!=INT_MAX){
        return dp[x];
    }
     else{
         return -1;
         
     }
     
                                 
}


int minimumElements(vector<int> &num, int x)
{
    
    return solveTab(num,x);
}