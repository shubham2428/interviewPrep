#include <iostream>
#include <vector>
using namespace std;

// Top down approach (dp+Memoization)
// Time complexity (O(N))
// Space O(N)

int fib(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    // step3 check if result already exist return result no need to go for recursion call
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step2 store the results inside the dp array
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    // step 1 creating dp 1d array of size n+1;
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << fib(n, dp) << endl;
}