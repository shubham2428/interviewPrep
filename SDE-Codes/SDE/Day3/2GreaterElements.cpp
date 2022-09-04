#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



int solve(vector<int> &input){

    unordered_map<int, int> mp;

    for(int i =0;i<input.size();i++){
        mp[input[i]]++;
    }

    for(auto ele : mp){
        if(ele.second > (float)(input.size()/2)){
            return ele.first;
        }
    }

    return -1;


}

int solveOptimal(vector<int> &input){

    int count=0;
    int currentEle=0;

    for(auto num : input ){
        if(count==0){
            currentEle=num;
        }

        if(currentEle==num){
            count=count+1;
        }
        else{
            count=count-1;
        }
    }

    return currentEle;
}



int main(){

    vector<int> input;
    input.push_back(2);
    input.push_back(2);
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    input.push_back(2);

    cout << solve(input) << endl;

}