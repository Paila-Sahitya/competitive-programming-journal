#include<bits/stdc++.h>
using namespace std;
 
void func(vector<vector<char>> &grid, vector<vector<int>>&vis, int n, int m){
    queue<pair<pair<int,int>, string>> q;
    int dr[]={-1, 0, 1, 0};
    int dc[]={0, -1, 0, 1};
    char d[]={'U', 'L', 'D', 'R'};
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                q.push({{i, j}, ""});
                break;
            }
        }
        if(!q.empty()) break;
    }
 
    int level=0;
    while(!q.empty()){
        level++;
        int size=q.size();
        while(size--){
            auto [r, c]=q.front().first;
            auto path=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(grid[nr][nc]=='B'){
                        path+=d[i];
                        cout<<"YES"<<"\n"<<level<<"\n"<<path<<"\n";
                        return;
                    }
                    if(grid[nr][nc]=='.'&& !vis[nr][nc]){
                        path+=d[i];
                        q.push({{nr, nc}, path});
                        vis[nr][nc]=1;
                        path=path.substr(0,path.size()-1);
                    }
                }
            }
 
        }
    }
    cout<<"NO"<<"\n";
}
 
void funcoptimized(vector<vector<char>> &grid, vector<vector<int>>&vis, int n, int m){
    queue<pair<int,int>> q;
    vector<vector<char>> dir(n, vector<char>(m));
    int dr[]={-1, 0, 1, 0};
    int dc[]={0, -1, 0, 1};
    char d[]={'U', 'L', 'D', 'R'};
 
    int sr=-1, sc=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                sr=i, sc=j;
                q.push({i, j});
                break;
            }
        }
        if(!q.empty()) break;
    }
 
    int level=0;
    while(!q.empty()){
        level++;
        int size=q.size();
 
        while(size--){
            auto [r, c]=q.front();
            q.pop();
 
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
 
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    
 
                    if(grid[nr][nc]=='B'){
                        vis[nr][nc]=1;
                        dir[nr][nc]=d[i];
 
                        cout<<"YES"<<"\n"<<level<<"\n";
                        string path="";
                        int cr=nr, cc=nc;
 
                        while(cr!=sr || cc!=sc){
                            char cd=dir[cr][cc];
                            path+=cd;
                            if(cd=='U') cr++;
                            else if(cd=='D') cr--;
                            else if(cd=='L') cc++;
                            else if(cd=='R') cc--;
                                                        
                        }
                        reverse(path.begin(), path.end());
                        cout<<path<<"\n";
                        return;
                    }
                    if(grid[nr][nc]=='.'&& !vis[nr][nc]){
                        dir[nr][nc]=d[i];
                        q.push({nr, nc});
                        vis[nr][nc]=1;
                    }
                }
            }
 
        }
    }
    cout<<"NO"<<"\n";
}
int main(){
 
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    funcoptimized(grid, vis, n, m);
    return 0;
}