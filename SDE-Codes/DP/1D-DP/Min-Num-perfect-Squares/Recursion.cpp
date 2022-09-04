#include<iostream>
using namespace std;

int solve(int n){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    
	    int ans=n; // kyuki maximum toh 1ke square se bn kste hain and vo n ke equal he honge
	    
	    for(int i =1;i*i<=n;i++){
	        int temp=i*i;
	        ans=min(ans,solve(n-temp));
	        
	    }
	    
	    return ans;
        }
	int MinSquares(int n)
	{
	    return solve(n);
	}
	