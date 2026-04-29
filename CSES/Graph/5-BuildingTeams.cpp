#include<bits/stdc++.h>
using namespace std;

class Disjoint{
public:
    vector<int> parent, size;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void uniona(int u, int v){
        int up=findUPar(u);
        int vp=findUPar(v);
        if(up==vp) return;
        if(size[up]>size[vp]){
            size[up]+=size[vp];
            parent[vp]=up;
        }
        else{
            size[vp]+=size[up];
            parent[up]=vp;
        }
    }
};

bool bipartite(int start, vector<vector<int>>&adj, vector<int> &col){
    queue<int> q;
    q.push(start);
    col[start]=1;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it: adj[node]){
            if(col[it]==-1){
                col[it]=col[node]==1?2:1;
                q.push(it);
            }
            else if(col[it]==col[node]){
                return false;
            }
        }
    }
    return true;
}

int main(){

    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> col(n+1, -1);
    
    bool breaks=false;
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            if(!bipartite(i, adj, col)){
                breaks=true;
                break;
            }
        }
    }

    if(breaks) cout<<"IMPOSSIBLE"<<"\n";
    else{
        for(int i=1;i<=n;i++){
            cout<<col[i]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}