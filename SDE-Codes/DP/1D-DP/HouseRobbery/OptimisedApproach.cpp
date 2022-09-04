#include<iostream>
#include<vector>
using namespace std;


/// this function is written same as maximum sum of non adjacent elements in which
// we have discussed all the optimised appraoch, phele use dekho
long long int solve(vector<int> &nums){

    long long int n=nums.size();
    
    long long int prev1=nums[0]; // accoriding to base case
    long long int prev2=0; // according to base case in recursion
    
    for(int i=1;i<n;i++){
        long long int inclusive=prev2+nums[i];
        long long int exclusion=prev1+0;
        long long int ans=max(inclusive,exclusion);
        prev2=prev1;
        prev1=ans;
    }
    
    return prev1;
}





long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> includefirstindex;
    vector<int> includelastindex;
    
    
    int n=valueInHouse.size();
    
    if(n==1){
        return valueInHouse[0];
    }
    
    for(int i =0;i<n;i++){
        if(i!=n-1){
            includefirstindex.push_back(valueInHouse[i]);
        }
        if(i!=0){
             includelastindex.push_back(valueInHouse[i]);
        }
    }

    return max(solve(includefirstindex),solve(includelastindex));
}