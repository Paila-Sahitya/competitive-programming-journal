#include<bits/stdc++.h>
using namespace std;

int main(){

    int h, w, n;
    cin>>h>>w>>n;
    // vector<pair<int,int>> q(n);
    for(int i=0;i<n;i++){
        int r, v;
        cin>>r>>v;
        if(r==1){
            h=h-v;
            cout<<v*(w)<<"\n";
        }
        else{
            w=w-v;
            cout<<v*(h)<<"\n";
        }
    }


    return 0;
}