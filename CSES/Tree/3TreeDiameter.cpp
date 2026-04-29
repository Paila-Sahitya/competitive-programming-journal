#include<bits/stdc++.h>
using namespace std;

int dia(int node, int parent, vector<vector<int>>&adj, int& ans){
    // vis[node]=1;
    int maxi1=0, maxi2=0;
    for(auto it: adj[node]){
        int curr;
        if(it==parent) continue;
        curr=dia(it,node, adj, ans);
        if(curr>maxi1){
            maxi2=maxi1;
            maxi1=curr;
        }
        else if(curr>maxi2) maxi2=curr;
    }
    ans=max(ans, maxi1+maxi2);
    return 1+max(maxi1, maxi2);
}

int main(){

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   int ans=0;
    dia(1,-1, adj, ans);
    cout<<ans<<"\n";

    return 0;
}