#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, k;
    cin>>n>>k;
    int total=n;
    int cnt=0;
    n++;
    while(total<k){
        total+=n;
        cnt++;
        n++;
    }
    cout<<cnt<<"\n";

    return 0;
}