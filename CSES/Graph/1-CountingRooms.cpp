#include<bits/stdc++.h>
using namespace std;
 
class Disjoint{
public:
    vector<int> parent, size;
    Disjoint(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void uniona(int u, int v){
        int up=findUpar(u);
        int vp=findUpar(v);
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
int main(){
 
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
 
    int cnt=0;
    
    int dr[]={-1, 0, 1, 0};
    int dc[]={0, -1, 0, 1};
 
    vector<int> nodes;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                nodes.push_back(i*m+j);
            }
        }
    }
    Disjoint ds(nodes.size());
    for(int i=0;i<nodes.size();i++){
        mpp[nodes[i]]=i;
    }
    for(int i=0;i<nodes.size();i++){
        int r=nodes[i]/m;
        int c=nodes[i]%m;
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='.'){
                ds.uniona(i, mpp[nr*m+nc]);
            }
        }
    }
    for(int i=0;i<ds.parent.size();i++){
        if(i==ds.findUpar(i)) cnt++;
    }
    cout<<cnt<<"\n";
 
    return 0;
}
