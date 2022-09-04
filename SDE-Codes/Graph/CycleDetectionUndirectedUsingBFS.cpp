#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;


bool isCyclicBFS(int src, unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjList){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        for(auto neighbour:adjList[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){   // condition for become cyclic
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
            
        }
    }
    return false;
    
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    
    unordered_map<int,list<int>> adjList;
    
    for(int i =0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //to handle all the graph components
    unordered_map<int,bool> visited;
    
    
    for(int i =0;i<n;i++){
        if(!visited[i]){
            bool ans= isCyclicBFS(i,visited,adjList);
            
            if(ans==1){
                return "Yes";
            }
        }
        
    }
    return "No";
}
