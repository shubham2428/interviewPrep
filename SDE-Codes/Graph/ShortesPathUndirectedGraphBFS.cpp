#include<iostream>
#include<unordered_map>
#include<queue>
#include<stack>
#include<list>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    // create an adj list
    unordered_map<int,list<int>> adj;
    
    for(int i =0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(v);
    }
    
    // do bfs;
    
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    
    queue<int> q;
    
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                parent[neighbour]=front;
                q.push(neighbour);
               
            }
        }
    }
    
    // prepare shortest path
    
    vector<int> ans;
    
    int currentNode=t;
    ans.push_back(t);
    
    while(currentNode!=s){
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}
