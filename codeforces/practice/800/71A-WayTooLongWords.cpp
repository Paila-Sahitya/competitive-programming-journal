#include<bits/stdc++.h>
using namespace std;

void optimizeLong(string s){
    int n=s.size();
    if(n<=10){
        cout<<s;
        return;
    }
    string op="";
    int mid=n-2;
    op+=s[0]+to_string(mid)+s[n-1];
    cout<<op;
}

int main(){
    int n;
    cin>>n;
    vector<string> queries(n);
    for(int i=0;i<n;i++) cin>>queries[i];

    for(int i=0;i<n;i++){
        optimizeLong(queries[i]);
        cout<<endl;
    }

    return 0;
}