#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solveHelper(vector<int> arr, int size, vector<int> &ans, int sum, int index){
    if(index==size){
        ans.push_back(sum);
        return;
    }


    // pick the current index element 

    solveHelper(arr, size,ans,sum+arr[index],index+1);

    // not pick

    solveHelper(arr,size,ans,sum,index+1);




}

vector<int> solve(vector<int> arr, int size){
    vector<int> ans;
    int sum=0;
    int index=0;
    solveHelper(arr, size, ans,sum,index);
    return ans;
}

int main()
{
    vector<int> arr{3, 1, 2};
    vector<int> ans = solve(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}