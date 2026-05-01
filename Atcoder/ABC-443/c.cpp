#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int open=0;
    int prev=0;
    for(int i=0;i<n;i++){
        if(prev<=arr[i]){
            // cout<<arr[i]-prev<<" ";
            open+=arr[i]-prev;
            prev=arr[i]+100;
        }
    }
    open+=(t-prev)>0?t-prev:0;
    cout<<open<<"\n";

    return 0;
}