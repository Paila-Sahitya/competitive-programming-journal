#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<char>> flag(n, vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>flag[i][j];
        }
    }
    int prev=-1;
    bool check=true;

    for(int i=0;i<n;i++){
        char curr=flag[i][0];
        if(i>0 && curr==flag[i-1][0]) check=false;

        for(int j=0;j<m;j++){
            if(flag[i][j]!=curr) check=false;
        }
    }

    if(check) cout<<"YES";
    else cout<<"NO";

    return 0;
}