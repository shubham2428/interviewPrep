#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDulpicatesUsingFrequency(vector<int> &arr)
{
    int size = arr.size();
    int freq[size + 1] = {0};

    for (int i = 0; i < size; i++)
    {

        if (freq[arr[i]] == 0)
        {
            freq[arr[i]] += 1;
        }
        else
        {
            return arr[i];
        }
    }

    return 0;
}
int findDuplicateUsingSorting(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int size = arr.size();

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return arr[i];
        }
    }
    return 0;
}

// this is most optimal approach with T.C is linear and space is constant;
int findDulpicatesUsingCycleMethod(vector<int> &arr)
{

    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);

    fast = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main()
{
    vector<int> arr;
    arr = {1, 3, 4, 2, 3};
    cout << "The duplicate element is " << findDulpicatesUsingCycleMethod(arr) << endl;
}