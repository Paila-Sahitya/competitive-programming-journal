#include<bits/stdc++.h>
using namespace std;

//rank i->i+1 req is di

void transitionYears(vector<int> &req, int a, int b){
    int n=req.size();
    int years=0;
    for(int i=a;i<b;i++){
        years+=req[i];
    }
    cout<<years;
}
int main(){
    int n;
    cin>>n;
    vector<int> req(n);
    for(int i=1;i<n;i++){
        cin>>req[i];
    }
    int a, b;
    cin>>a>>b;

    transitionYears(req, a, b);

    return 0;
}