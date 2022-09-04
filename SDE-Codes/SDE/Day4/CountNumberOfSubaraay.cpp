#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int> &a, int b){
    int count=0;
    for(int i =0;i<a.size();i++){
        int curr_xor=0;
        for(int j=i;j<a.size();j++){
            curr_xor^=a[j];
            if(curr_xor==b){
                count++;
            }
        }
    }

    return count;

}

int main(){
    vector<int> A{ 4,2,2,6,4 };
    cout << solve(A,6) << endl;
}