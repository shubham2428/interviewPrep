#include<vector>
#include<iostream>
using namespace std;
int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int >> &dp ){
    
    //base case
    // check if only 1 element is present to steal ,if it under capacity
    //include it otherwise return 0
    
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    

    //step3
    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }
    
    if(weight[index] <=capacity){
        
       int include= value[index] + solve(weight,value,index-1,capacity-weight[index],dp);
        
        int exclude= 0 + solve(weight,value,index-1,capacity,dp);
        
        //step2
        dp[index][capacity] = max(include,exclude);
        return dp[index][capacity];
    }
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 

{
    //step 1: creating a 2d dp 
    vector<vector<int > > dp (n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}