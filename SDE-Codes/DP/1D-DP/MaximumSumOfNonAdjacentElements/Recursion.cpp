#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int> &nums,int index){
    if(index<0){
        return 0;
    }
    
    if(index==0){
        return nums[0];
    }
    
    
    int include=solve(nums,index-2) + nums[index];
    int exclude=solve(nums,index-1) + 0;
    
    int ans=max(include,exclude);
    return ans;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int index=nums.size()-1;
   // int ans=0;
    return solve(nums,index);
}