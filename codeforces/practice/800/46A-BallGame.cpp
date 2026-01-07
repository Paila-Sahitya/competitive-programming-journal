#include<bits/stdc++.h>
using namespace std;

void ballGame(int n){
    int start=1;
    int i=1;
    int inc=1;
    vector<int> child(n);
    while(i<n){
        child[i]=(start+i)%n;
        if(child[i]==0) child[i]=n;
        start=child[i];
        i++;
    }
    for(int i=1;i<n;i++) cout<<child[i]<<" ";
}
int main(){

    int n;
    cin>>n;
    //n-1 throws
    ballGame(n);

    return 0;
}