#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int rstart=-1, rend=-1;
    for(int i=0;i<n;i++){
        bool rcheck=false;
        for(int j=0;j<m;j++){
            if(grid[i][j]=='*'){
                rcheck=true;
            }
        }
        if(rcheck && rstart==-1) rstart=i;
        if(rcheck) rend=i;
    }

    int cstart=-1, cend=-1;
    for(int j=0;j<m;j++){
        bool ccheck=false;
        for(int i=0;i<n;i++){
            if(grid[i][j]=='*'){
                ccheck=true;
            }
        }
        if(ccheck && cstart==-1) cstart=j;
        if(ccheck) cend=j;
    }

    for(int i=rstart;i<=rend;i++){
        for(int j=cstart;j<=cend;j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    

    return 0;
}

//.......
// ..***..
// ..*....
// ..***..
// ..*....
// ..***..