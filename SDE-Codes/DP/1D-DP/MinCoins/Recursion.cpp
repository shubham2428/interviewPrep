#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> &num, int x)
{
    if (x == 0)
    {
        return x;
    }
    if (x < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveRec(num, x - num[i]);

        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1); // we are adding 1 to the answer beacuse  in line number
                                       // 16 we are not adding that pirticular coin for that call is going
        }
    }

    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    int ans = solveRec(num, x);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}