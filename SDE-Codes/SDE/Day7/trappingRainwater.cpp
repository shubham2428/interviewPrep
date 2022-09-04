#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &arr)
{
    int watertrapped = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // calculate left max for current index
        int j = i;
        int leftmax = 0;
        int rightmax = 0;
        while (j >= 0)
        {
            leftmax = max(leftmax, arr[j]);
            j--;
        }

        j = i;

        while (j < arr.size())
        {
            rightmax = max(rightmax, arr[j]);
            j++;
        }

        watertrapped += min(leftmax, rightmax) - arr[i];
    }

    return watertrapped;
}


int trapBetter(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}

int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
}