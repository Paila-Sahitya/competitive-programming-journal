#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;
    vector<vector<char>> adj(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int> (m, 1));
    vector<vector<char>> path(n, vector<char>(m, ' '));
    queue<pair<int, int>> q;
    queue<pair<int,int>> aq;

    int sr=-1, sc=-1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
            if(adj[i][j]=='#') vis[i][j]=-1;
            if(adj[i][j]=='M'){
                q.push({i, j});
                vis[i][j]=0;
            }
            else if(adj[i][j]=='A'){
                sr=i, sc=j;
                vis[i][j]=2;
                aq.push({i, j});
            }
        }
    }

    string ans="";

    int dr[]={-1, 0, 1, 0};
    int dc[]={0, -1, 0, 1};
    char d[]={'U','L', 'D', 'R'};

    bool found=false;
    //check monster spread till A reaches boundary
        
    while((!aq.empty())&&!found){
        //Monster spread
        int size1=q.size();
        while(size1--){
            auto [r, c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]>0){
                    vis[nr][nc]=0;
                    q.push({nr, nc});
                }
            }
        }

        //move A
        int size2=aq.size();
        while(size2--){
            auto [r, c]=aq.front();
            aq.pop();

            if((r==0 || r==n-1 || c==0 || c==m-1)){
                int cr=r, cc=c;
                while(cr!=sr || cc!=sc){
                    char cd=path[cr][cc];
                    ans+=cd;
                    if(cd=='U') cr++;
                    else if(cd=='D') cr--;
                    else if(cd=='L') cc++;
                    else if(cd=='R') cc--;
                }
                reverse(ans.begin(), ans.end());
                found=true;
                break;
            }

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==1){
                    vis[nr][nc]=2;
                    aq.push({nr, nc});
                    path[nr][nc]=d[i];
                }
            }
        }
        if(found) break;
    }

    if(found){
        cout<<"YES"<<"\n"<<ans.size()<<"\n";
        cout<<ans<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }

    return 0;
}