#include<bits/stdc++.h>
using namespace std;

void maxEarning(vector<int> &tv, int m){
    int n=tv.size();
    sort(tv.begin(), tv.end());
    int earning=0;
    for(int i=0;i<n;i++){
        if(m==0) break;
        if(tv[i]<0) earning+=abs(tv[i]);
        m--;
    }
    cout<<earning;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> tv(n);
    for(int i=0;i<n;i++){
        cin>>tv[i];
    }
    maxEarning(tv, m);
    return 0;
}