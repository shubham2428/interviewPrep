#include <iostream>
#include<cmath>
using namespace std;


// t.c O(n*m) ,S.C(1)
void merge(int arr1[], int arr2[], int n, int m)

{
    int i, k;

    for (i = 0; i < n; i++)
    {

        if (arr1[i] > arr2[0])
        {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;
        }

        int first = arr2[0];
        for (k = 1; k < m && arr2[k] < first; k++)
        {
            arr2[k - 1] = arr2[k];
        }

        arr2[k - 1] = first;
    }
}



// this is enhanced approrach with time complexity O(m+n) and space is O(1) // OPTIMAL APPROACH
void mergeGap(int arr1[], int arr2[], int n, int m)
{
    int gap =  ceil((float)(m+n) / 2);

    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < (n + m))
        {
            if (j < n && arr1[i] > arr1[j])
            {
                swap(arr1[i], arr1[j]);
            }
            else if (j >= n && i < n && arr1[i] > arr2[j - n])
            {
                swap(arr1[i], arr2[j - n]);
            }
            else if (j >= n && i >= n && arr2[i - n] > arr2[j - n])
            {
                swap(arr2[i - n], arr2[j - n]);
            }
            j++;
            i++;
        }
        if (gap == 1)
        {
            gap = 0;
        }
        else
        {
            gap = ceil((float)gap / 2);
        }
    }
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    cout << "Before merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
  //  merge(arr1, arr2, 5, 3);
    mergeGap(arr1,arr2,5,3);

    cout << "After merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
}