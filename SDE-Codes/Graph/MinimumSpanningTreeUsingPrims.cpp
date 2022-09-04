
// This is known as prims algorithm 
// Time complexity of this algorithm is O(n^2);

#include<iostream>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
   unordered_map<int,list<pair<int,int> > > adj;
    
    for(int i =0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));   
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    
    
    // starts the algo
    key[1]=0;
    parent[1]=-1;
    
    for(int i =0;i<n;i++){
        int mini=INT_MAX;
        int u;
        
        //finding minimum vali value
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        
        // mark min node as true
        
        mst[u]=true;
        
        
        // check its adj nodes
        
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
                
            }
        }
        
    }
    
   vector<pair<pair<int, int>, int>> result;
    
    for(int i =2;i<=n;i++){
        result.push_back({{parent[i],i},key[i]});
    }
    
    return result;
    
    
}
