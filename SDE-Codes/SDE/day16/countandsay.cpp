#include <iostream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        string res;
        // cout<<"prev = "<<prev<<endl;
        // cout<<"n = "<<n<<endl;
        int cnt = 1;
        if (prev.size() == 1)
        {
            res += to_string(cnt);
            res += prev[0];
        }
        for (int i = 0; i < prev.size(); i++)
        {
            if (i + 1 < prev.size() && prev[i] != prev[i + 1])
            {
                res += to_string(cnt);
                res += prev[i];
                cnt = 1;
            }
            if (i + 1 < prev.size() && prev[i] == prev[i + 1])
            {
                cnt++;
            }
            if (i == prev.size() - 1 && i - 1 >= 0)
            {
                res += to_string(cnt);
                res += prev[i];
            }
        }
        // cout<<"res = "<<res<<endl;
        return res;
    }
};