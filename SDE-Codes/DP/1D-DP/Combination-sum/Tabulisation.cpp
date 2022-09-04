#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &num, int tar){
    
    //analysing base case
    vector<int> dp(tar+1,0);
    dp[0]=1;
    
    // traversing for target 1 to tar
    for(int i =1;i<=tar;i++){
        
        // traversing for all the value in nums
        for(int j =0;j<num.size();j++){
            if((i-num[j])>=0){
                 dp[i] += dp[i-num[j]];   
            }
           
        }
    }
    return dp[tar];
        
}

int findWays(vector<int> &num, int tar)
{
    
    // step1 : create a dp of size tar+1;
    return solve(num,tar);
}