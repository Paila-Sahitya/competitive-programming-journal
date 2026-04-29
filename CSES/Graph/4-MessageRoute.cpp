#include<bits/stdc++.h>
using namespace std;

void func(vector<vector<int>> adj, int n){
    vector<int> vis(n+1, 0);
    vector<int> prev(n+1, 0);

    queue<int> q;
    q.push(1);
    vis[1]=1;

    int level=0;
    while(!q.empty()){
        level++;
        int size=q.size();
        
        while(size--){
            int cnode=q.front();
            q.pop();


            if(cnode==n){
                cout<<level<<"\n";
                vector<int> nodes;
                while(true){
                    nodes.push_back(cnode);
                    if(cnode==1) break;
                    cnode=prev[cnode];
                }
                reverse(nodes.begin(), nodes.end());
                for(auto it2: nodes) cout<<it2<<" ";
                cout<<"\n";
                return;
            }

            for(auto it: adj[cnode]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                    prev[it]=cnode;
                }
                
            }
        }
    }

    cout<<"IMPOSSIBLE"<<"\n";
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
    
    func(adj, n);
    return 0;
    
}