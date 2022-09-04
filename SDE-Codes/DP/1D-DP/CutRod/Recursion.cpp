#include <iostream>
#include <limits.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    // base case

    if (n == 0)
    {
        return 0;
    }

    if (n < 0)
    {
        return INT_MIN;
    }

    int a = solve(n - x, x, y, z) + 1; // we are adding 1 because reult is coming for n-x value and for making it n we have to add that component as well
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    return max(a, max(b, c));
}

int cutSegments(int n, int x, int y, int z)
{
    int ans = solve(n, x, y, z);
    if (ans < 0)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}