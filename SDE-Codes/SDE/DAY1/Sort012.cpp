#include <iostream>
using namespace std;

int* sort(int nums[])
{
  // THIS IS ALSO KNOWN AS DUTCH NATIONAL FLAG ALGORITHM
    int lo = 0;
    int mid = 0;
    int hi = 5;

    while (mid <= hi)
    {
        switch (nums[mid])
        {

        // If the element is 0
        case 0:
            swap(nums[lo++], nums[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(nums[mid],nums[hi--]);
            break;
        }
    }

    return nums;
}

int main()
{
    int arr[6] = {1, 2, 0, 1, 2, 2};

    int *ptr = sort(arr);

    for(int i =0;i<6;i++){
        cout << ptr[i] << endl;

    }
}