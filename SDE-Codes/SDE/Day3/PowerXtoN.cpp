#include<iostream>
#include<vector>
using namespace std;


// time complexity O(n);
double pow(double x,int n){

    double ans=1.0;
    for(int i =0;i<n;i++){
        ans=ans*x;
    }

    return ans;
}


// Time complexcity is O(logn)

double powOptimal(double x, int n){

    double ans=1.0;
    long long nn=n;

    if(n<0){
        nn= -1*nn ;
    }

    while(nn){
        if(nn%2){
            ans=x*ans;
            nn=nn-1;


        }

        else{
            x=x*x;
            nn=nn/2;
        }
    }

    if(n<0){
        return (double)(1.0)/(double)(ans);
    }
    else{
        return ans;
    }
}



int main(){

    cout<< pow(2,10) << endl;
    cout << powOptimal(2,10)<< endl;
}