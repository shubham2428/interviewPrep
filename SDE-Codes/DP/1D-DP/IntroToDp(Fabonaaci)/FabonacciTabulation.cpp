#include<iostream>
#include<vector>
using namespace std;


// Tabulation way
//time complexity O(N)'
//Space: O(N)

int main(){
    int n;
    cin>>n;
  
    //step 1 creating a dp array of size n+1;
    vector<int> dp(n+1);

    //step 2: Directly put base case scenario in dp

    dp[0]=0;
    dp[1]=1;
    
    // step 3: run a loop inside dp array to find next values
    for(int i =2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    cout << dp[n]<< endl;


}