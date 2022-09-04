#include<iostream>
#include<vector>
using namespace std;


bool Search(vector<vector<int> > &mat, int target){
    int colsize=mat.size();
    int rowsize=mat[0].size();

    int low=0;
    int high=(rowsize*colsize)-1;


    while(low<=high){
        int mid = (low + (high - low) / 2);

        if(mat[mid/rowsize][mid % rowsize]==target){  
            return true;
        }

        else if(mat[mid/rowsize][mid % rowsize] > target){
           high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return false;


}


