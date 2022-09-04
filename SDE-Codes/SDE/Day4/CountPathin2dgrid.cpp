#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int countPaths(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }

    int uniquePathsDP(int m , int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solveDP(0,0,m,n,dp);
    }
   //space complexiy of dp solution is m*n;
   // time complexty is m*n;

    int solveDP(int i , int j, int n , int m , vector<vector<int>> &dp){
         if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        else 
            dp[m][n]=countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);

        


    }
};
int main()
{
    Solution obj;
    int totalCount= obj.uniquePaths(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}