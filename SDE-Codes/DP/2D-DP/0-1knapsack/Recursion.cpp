#include<iostream>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
    
    //base case
    // check if only 1 element is present to steal ,if it under capacity
    //include it otherwise return 0
    
    if(index==0){
        if(weight[index]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    
    if(weight[index] <=capacity){
        
        int include=value[index] + solve(weight,value,index-1,capacity-weight[index]);
        
        int exclude=0+solve(weight,value,index-1,capacity);
        
        return max(include,exclude);
    }
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight,value,n-1,maxWeight);
}