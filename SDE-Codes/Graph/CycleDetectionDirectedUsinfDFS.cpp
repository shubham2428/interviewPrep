#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

bool checkCycleDFS(int node,unordered_map<int,bool> &visited, unordered_map<int ,bool> &dfsVisited,unordered_map<int,list<int> > &adjList){
    visited[node]=true;
    dfsVisited[node]=true;
    
    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected=checkCycleDFS(neighbour,visited,dfsVisited,adjList);
            if(cycleDetected){
                return true;
            }
            
        }
        else if(dfsVisited[neighbour]){
                return true;
            }
    }
    
    dfsVisited[node]=false;
        return false;
    
    
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int,list<int> > adjList;
    
    for(int i =0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adjList[u].push_back(v);  // because it is an directed graph only
    }
    
    
    // call dfs for all component;
    unordered_map<int,bool> visited;
    unordered_map<int ,bool> dfsVisited;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool cycleFound=checkCycleDFS(i,visited,dfsVisited,adjList);
            if(cycleFound){
                return true;
            }
        }
        
    }
    return false;
    
}