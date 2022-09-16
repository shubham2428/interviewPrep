#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution 
{
    
    public:
    
    bool knows(vector<vector<int> > &M, int a,int b, int n){
        if(M[a][b]==1){
            return true;
        }
        else{
            false;
        }
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i =0;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
            
        }
        
        int ans=s.top();
        
        int countzeros=0;
        
        int countone=0;
        
        // check rowcount
        
        for(int i =0;i<n;i++){
            if(M[ans][i]==0){
                countzeros++;
            }
        }
        
        //check coloum 
        
        for(int i =0;i<n;i++){
            if(M[i][ans]==1){
                countone++;
            }
        }
        
        
        if(countzeros==n && countone==n-1){
            return ans;
        }
        else{
            return -1;
        }
    }
};