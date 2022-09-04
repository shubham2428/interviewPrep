#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &input, int target)
{
    int size = input.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (input[i] + input[j] == target)
            {
                cout << i << " " << j << endl;
                return;
            }
        }
    }
}

void solveBetter(vector<int> &input, int target)
{

    int size = input.size();
    sort(input.begin(), input.end());

    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        if (input[start] + input[end] == target)
        {

            cout << start << " " << end << endl;
            return;
        }
        else if (input[start] + input[end] > target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
}

void solveOptimal(vector<int> &input, int target)
{

    unordered_map<int, int> mp;

    int size = input.size();

    for (int i = 0; i < input.size(); i++)
    {
        if (mp.find(target - input[i]) != mp.end())
        {
            cout << i << " " << mp[target - input[i]] << endl;
            return;
        }

        mp[input[i]] = i;
    }
}

int main()
{
    vector<int> input;
    input.push_back(2);
    input.push_back(7);
    input.push_back(11);
    input.push_back(15);

    int target = 9;

    // solve(input, target);
    // solveBetter(input, target);
    solveOptimal(input, target);

    return 0;
}
