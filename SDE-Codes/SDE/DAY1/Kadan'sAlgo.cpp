#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &arr, vector<int> &sub)
{

    int maxsum = INT_MIN;
    int size = arr.size();

    if (size == 1)
    { // edge case
        return 0;
    }

    for (int i = 0; i <= size - 1; i++)
    {
        for (int j = i; j <= size - 1; j++)
        {

            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
                if (sum > maxsum)
                {
                    sub.clear();
                    maxsum = sum;
                    sub.push_back(i);
                    sub.push_back(j);
                }
            }
        }
    }

    return maxsum;
}

int maxSubArrayTwoLoop(vector<int> &arr, vector<int> &sub)
{

    int max_sum = INT_MIN;
  for (int i = 0; i < arr.size(); i++) {
    int curr_sum = 0;
    for (int j = i; j < arr.size(); j++) {
      curr_sum += arr[j];
      if (curr_sum > max_sum) {
        sub.clear();
        max_sum = curr_sum;
        sub.push_back(i);
        sub.push_back(j);
      }
    }
  }
  return max_sum;
}


int KadansAlgo(vector<int> &arr, vector<int> &sub){

    int msf=INT_MIN;
    int meh=0;
    int size=arr.size();
    int start=0;

    for(int i =0;i<size;i++){
        meh+=arr[i];

        if(meh>msf){
            msf=meh;
            sub.clear();
            //sub.push_back(i);
            sub.push_back(start);
            sub.push_back(i);
        }

        if(meh<0){
            meh=0;
            start=i+1;
        }
    }

    return msf;
}



int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subarray;
    int lon = maxSubArray(arr, subarray);
    cout << "The longest subarray with maximum sum is " << lon << endl;
    cout << "The subarray is " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << arr[i] << " ";
    }
}