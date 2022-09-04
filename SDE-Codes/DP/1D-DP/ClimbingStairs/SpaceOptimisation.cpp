#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    
    int solve(vector<int>& cost,int n){
        
        // step 1 
        int prev2=cost[0];
        int prev1=cost[1];
        
        // step2
        for(int i =2;i<n;i++){
            int curr=cost[i]+min(prev1,prev2);

            // step3: updating the numbers
            prev2=prev1;
            prev1=curr;
        }
        
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=solve(cost,n);
        return ans;
        
    }
};