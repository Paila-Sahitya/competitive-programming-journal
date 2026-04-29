#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &parent, vector<vector<int>>&adj, vector<int>&vis, vector<int> &cycle){
    vis[node]=1;
    for(auto it: adj[node]){
        if(it==parent[node]) continue;
        if(!vis[it]){
            parent[it]=node;
            bool found=dfs(it, parent, adj, vis, cycle);
            if(found) return true;
        }
        else{
            int cnode=node;
            cycle.push_back(it);
            while(cnode!=it){
                cycle.push_back(cnode);
                cnode=parent[cnode];
            }
            cycle.push_back(it);
            return true;
        }
    }
    return false;
}
int main(){

    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src=-1;
    vector<int> par(n+1, -1);
    vector<int> vis(n+1, 0);
    vector<int> cycle;
    bool found=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            found=dfs(i, par, adj, vis, cycle);
            if(found) break;
        }
    }

    if(found){
        cout<<cycle.size()<<"\n";
        for(auto it: cycle) cout<<it<<" ";
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE";
    }


    return 0;
}