#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, 1});
    vector<long long> dis(n+1, LLONG_MAX);
    vector<int> vis(n+1, 0);
    dis[1]=0;
    vis[1]=1;

    while(!pq.empty()){
        auto [d, node]=pq.top();
        pq.pop();
        
        if(d>=dis[node] && node!=1) continue;
        dis[node]=min(dis[node], d);
        
        for(auto it: adj[node]){
            int nnode=it.first;
            long long nd=it.second;
            if(!vis[nnode] || d+nd<dis[nnode]){
                vis[nnode]=1;
                pq.push({d+nd, nnode});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
    return 0;
}