#define MOD 1000000007
#include<iostream>
using namespace std;
long long int countDerangements(int n) {
    //BASE CASE
    if(n==1){
        return 0;
    }// if n is 1 dearrangments possible he nhi hain
        
    if(n==2){
        return 1;  // agr sirf 2 elements hain eska matlab 1 he dearrangment possible hain
    }
        
        
    int ans =  ( ((n-1)% MOD) *( (countDerangements(n-1)%MOD)
                                 + (countDerangements(n-2)%MOD))%MOD);  // we are using mod beacuse it is requirement of questions
                              
    return ans;                    
    
}