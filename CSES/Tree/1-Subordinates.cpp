#include<bits/stdc++.h>
using namespace std;

//tree dp

int getchild(int node, vector<vector<int>> &adj, vector<int>& child){
    if(adj.empty()) return child[node]=0;
    int cnt=adj[node].size();
    for(auto it: adj[node]){
        if(child[it]!=-1) cnt+=child[it];
        else cnt+=getchild(it, adj, child);
    }
    return child[node]=cnt;
}
int main(){

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int v=2;v<=n;v++){
        int u;
        cin>>u;
        adj[u].push_back(v);
    }
    vector<int> child(n+1, -1);
    int cnt=getchild(1, adj, child);
    for(int i=1;i<=n;i++){
        cout<<child[i]<<" ";
    }
    return 0;
}