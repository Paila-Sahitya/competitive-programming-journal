#include<bits/stdc++.h>
using namespace std;

bool triangularNumber(int n){
    if(n<0) return false;
    for(int i=1;i<=n;i++){
        int area=i*(i+1)/2;
        if(area==n) return true;
        if(area>n) break;
    }
    return false;
}

int main(){

    int n;
    cin>>n;

    if(triangularNumber(n)) cout<<"YES";
    else cout<<"NO";

    return 0;
}