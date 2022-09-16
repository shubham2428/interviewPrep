#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
   stack<int> s;
   vector<int> ans(n);
    s.push(-1);
     
    for(int i =n-1;i>=0;i--){
        while(s.top()<=arr[i]){
            s.pop();  
        }
        
        // eska matlab mil gya h 
        ans[i]=s.top();
        s.push(arr[i]);
        
    }
    
    return ans;
    
}


int main(){

    vector<int> arr={5,7,1,7,6,0};
    vector<int> ans=nextSmallerElement(arr,6);

    for(auto i : ans){
        cout << i << endl;
    }

}