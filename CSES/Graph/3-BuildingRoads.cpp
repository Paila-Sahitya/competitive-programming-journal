#include<bits/stdc++.h>
using namespace std;

//build roads such all cities connected
// number of components-1 ->minimum extra roads required

class Disjoint{
public:
    vector<int> parent, size;
    Disjoint(int n){
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
        size.resize(n+1, 1);
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
            parent[vp]=up;
        }
    }
};

int main(){

    int n, m;
    cin>>n>>m;
    Disjoint ds(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        if(ds.findUPar(u)!=ds.findUPar(v)){
            ds.uniona(u, v);
        }
    }
    vector<int> par;
    for(int i=1;i<ds.parent.size();i++){
        if(i==ds.findUPar(i)){
            par.push_back(i);
        }
    }
    int extraedges=par.size()-1;
    cout<<extraedges<<"\n";
    for(int i=1;i<par.size();i++){
        cout<<par[i-1]<<" "<<par[i]<<"\n";
    }

    return 0;
}