#include<bits/stdc++.h>
using namespace std;


int main(){
    string months[]={"January", "February", "March", "April", "May","June","July","August","September","October","November","December"};

    string current_Month;
    cin>>current_Month;
    int wait;
    cin>>wait;

    int curr=0;
    for(int i=0;i<12;i++){
        if(current_Month==months[i]) curr=i;
    }
    int next=(curr+wait)%12;
    cout<<months[next];

    return 0;
}