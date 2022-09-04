#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int> v; // declaration of vector
    v.push_back(1);
    v.emplace_back(2); // it works exaclty as push_back but some people says it works faster than push_back;

    vector<pair<int,int> > vectorpair;

    vectorpair.push_back(make_pair(1,2));
    vectorpair.push_back({1,2}); // this is same as line number 14, changes in syntax only


    // suppose i want to create a vector with 5 indexs having 100 at everyplace

    vector<int> testVector(5,100);

    // supose we want to create the same vector with different name but same values'


    vector<int> copyVector(testVector);

    for(auto i : testVector){
        cout << i << endl;
    }


    cout << "printing the iterator things" << endl;


    // iterators

    vector<int> ittest={1,2,3,4};

    vector<int> :: iterator it = ittest.begin();  // it will point to memory location of 0th index value of vector

    cout << *(it) << endl;


    cout << "printing using loop" << endl;


    for(vector<int> :: iterator it =ittest.begin(); it<ittest.end();it++){
        cout << *(it) << endl;
    }

    // we can also replace the vector<int> :: iterator keyword using auto

   cout << "print after the changing sytax" << endl;
    for(auto it= ittest.begin();it<ittest.end();it++){
         cout << *(it) << endl;

    }


    // if we want to erase some data


    ittest.erase(ittest.begin()+2); // it will erase the second index element;

   for(vector<int> :: iterator it =ittest.begin(); it<ittest.end();it++){
        cout << *(it) << endl;
    }


  ittest.size(); // for size f an vector

  ittest.pop_back(); // remove the last elemet for array






}