#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> merge(vector<pair<int, int>> &arr)
{

    int size = arr.size();
    vector<pair<int, int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < size; i++)
    {
        int start = arr[i].first;
        int end = arr[i].second;

        if (!ans.empty())
        {
            if (start <= ans.back().second)
            {
                continue;
            }
        }

        for (int j = i + 1; j < size; j++)
        {

            if (end >= arr[j].first)
            {
                end = arr[j].second;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}

vector<vector<int>> mergeOptimal(vector<pair<int, int>> &arr)
{
    vector<vector<int>> merged;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {

        if (merged.empty() || merged.back()[1] < arr[i].first)
        {
            vector<int> temp = {arr[i].first, arr[i].second};
            merged.push_back(temp);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], arr[i].second);
        }
    }

    return merged;
}

int main()
{
    vector<pair<int, int>> arr;
    arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<pair<int, int>> ans = merge(arr);

    vector<vector<int>> ans1 = mergeOptimal(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it : ans1)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
}