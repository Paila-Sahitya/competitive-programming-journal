#include<bits/stdc++.h>
using namespace std;

int main(){
    int y, w;
    cin>>y>>w;
    int minD=max(y, w);
    int probNum=6-minD+1;
    int probDen=6;
    if(probNum%2==0){
        probDen/=2;
        probNum/=2;
    }
    if(probNum%3==0){
        probDen/=3;
        probNum/=3;
    }
    cout<<probNum<<"/"<<probDen;

    return 0;
}