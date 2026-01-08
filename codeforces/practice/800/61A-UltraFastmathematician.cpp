#include<bits/stdc++.h>
using namespace std;

int main(){

    string num1, num2;
    cin>>num1>>num2;

    int ans=0;
    string n1=(num1);
    string n2=(num2);
    string res="";
    // cout<<n1<<" "<<n2<<endl;
    for(int i=0;i<n1.size();i++){
        if(n1[i]==n2[i]) res+='0';
        else res+='1';
    }
    cout<<res;


    return 0;
}