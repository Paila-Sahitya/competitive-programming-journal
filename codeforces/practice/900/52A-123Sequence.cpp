#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    map<int, int> mpp;
    for(int i=0;i<n;i++) mpp[arr[i]]++;

    int maj=0;
    for(auto it: mpp){
        maj=max(maj, it.second);
    }
    int min_op=n-maj;
    cout<<min_op;
    
    return 0;
}