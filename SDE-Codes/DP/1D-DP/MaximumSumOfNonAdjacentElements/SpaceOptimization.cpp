#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &nums){

    int n=nums.size();
    
    int prev1=nums[0]; // accoriding to base case
    int prev2=0; // according to base case in recursion
    
    for(int i=1;i<n;i++){
        int inclusive=prev2+nums[i];
        int exclusion=prev1+0;
        int ans=max(inclusive,exclusion);
        prev2=prev1;
        prev1=ans;
    }
    
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
   // int index=nums.size()-1;
   // int n=nums.size();
    
    return solve(nums);
}