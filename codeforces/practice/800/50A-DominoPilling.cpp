#include<bits/stdc++.h>
using namespace std;

int dominoPlacing(int n, int m){
    int rowwise=n/2;
    int colwise=m/2;
    int cnt=0;
    if(n%2==0 && m%2==0) cnt= rowwise*m;
    else if(n%2==0) cnt=rowwise*m;
    else if(m%2==0) cnt=colwise*n;
    else{
        cnt=rowwise*m+ colwise;
    }
    return cnt;
}
int main(){
    int m, n;
    cin>>m>>n;

    cout<<dominoPlacing(m, n);

    return 0;
}