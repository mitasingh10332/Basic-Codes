#include <bits/stdc++.h>
using namespace std;

int get_comp( int idx, vector<bool>&visited, vector<vector<int>>&adj){

    if(visited[idx])
         return 0;
    visited[idx]= true;
    int ans= 1;
    for(auto i : adj[idx]){
        if(!visited[i]){
            ans+= get_comp(i,visited, adj);
            visited[i]=true;
        }
    }
    return ans;
}

int main(){
   int n, m;
   cin>>n>>m;
   vector<int>components(n);
   vector<vector<int>>adj(n);
   vector<bool> visited(n,0);
    for(int i = 0; i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    for(int i =0;i<n;i++)
    {
        if(!visited[i]){
            components.push_back(get_comp(i, visited, adj));
        }
    }

    for(auto i : components)
    {
        if(i)
        cout<<i<<" ";
    }

    return 0;
}
