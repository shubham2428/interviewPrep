#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// this approach is so tricky again listen to the video
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
   int ans=0;
    
   queue<pair<int,int>> monthly;
   queue<pair<int,int>> weekly;
    
   for(int day : days){
       
       
       // step1 remove expired days
       
       while(!monthly.empty() && monthly.front().first + 30 <=day){
           monthly.pop();
       }
       
        while(!weekly.empty() && weekly.front().first + 7 <=day){
           weekly.pop();
       }
       
       // step2 : update the queue
       
       monthly.push(make_pair(day,ans+cost[2]));
       weekly.push(make_pair(day,ans+cost[1]));
       
       // update ans;
       ans=min(ans+cost[0],min(monthly.front().second,weekly.front().second));
   }
    
    return ans;
    
    
   
}