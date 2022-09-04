#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> RemoveDuplicates(vector<int> &input){

    unordered_map<int,int> mp;
    vector<int> temp;

    for(int i =0;i<input.size();i++){
        mp[input[i]]++;
    }

   for(auto ele: mp){
    temp.push_back(ele.first);
   }


    return temp;

}


vector<int> RemoveDuplicatesInplace(vector<int> &input){
    int i =0;
    int j=1;

    for(j;j<input.size();j++){
        if(input[i]!=input[j]){
            i++;
            input[i]=input[j];
        }
    }

    return input;
}


int main(){
    vector<int> input={1,2,2,2,3,3,4,4,4};

    vector<int> ans=RemoveDuplicatesInplace(input);

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}