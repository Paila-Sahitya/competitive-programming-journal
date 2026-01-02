// A. Super Agent


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=3;
    vector<vector<char>> line(3, vector<char>(3));

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>line[i][j];
        }
    }
    set<pair<int, int>> st;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(line[i][j]=='X'){
                st.insert({i,j});
            }
        }
    }

    bool check=true;
    for(auto it:st){
        int row=it.first, col=it.second;
        int dr[]={+2, 0, -2, 0};
        int dc[]={0, +2, 0, -2};
        bool isSym=false;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 && nrow<3 && ncol>=0&& ncol<3){
                // cout<<nrow<<" "<<ncol<<endl;
                if(st.find({nrow, ncol})!=st.end()){
                    isSym=true;
                }
            }
        }
        if(row==1 && col==1) isSym=true;
        if((row==0 && col==0 && st.find({2, 2})!=st.end())|| 
            (row==2 && col==2 &&st.find({0, 0})!=st.end()) || 
            (row==0 && col==2 && st.find({2, 0})!=st.end())||
            (row==2 && col==0 && st.find({0,2})!=st.end())){
                isSym=true;
        }
        if(!isSym ) check=false;
        
    }
    if(check) cout<<"YES";
    else cout<<"NO";

    return 0;
}