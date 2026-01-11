#include<bits/stdc++.h>
using namespace std;


void func(int n, int m){
    vector<int> primes(60, 0);
    primes[0]=1;
    primes[1]=1;

    for(int i=2;i<60;i++){
        if(primes[i]==0){
            int j=2;
            while(j*i<60){
                primes[i*j]++;
                j++;
            }
        }
    }
    bool found=true;

    if(primes[n]==0 && primes[m]==0){
        for(int i=n+1;i<m;i++){
            if(primes[i]==0) found=false;
        }
    }
    else found=false;

    if(found) cout<<"YES";
    else cout<<"NO";
}

int main(){

    int n, m;
    cin>>n>>m;

    func(n, m);

    return 0;
}