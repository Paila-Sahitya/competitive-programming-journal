#include<bits/stdc++.h>
using namespace std;

void borze_Code(string s){
    int n=s.size();
    string ans="";
    int i=0;
    while(i<n){
        if(i<n-1 && s[i]=='-' && s[i+1]=='.'){
            ans+='1';
            i+=2;
        }
        else if(i<n-1 && s[i]=='-' && s[i+1]=='-'){
            ans+='2';
            i+=2;
        }
        else{
            ans+='0';
            i++;
        }
    }
    cout<<ans;
}
int main(){

    string s;
    cin>>s;

    borze_Code(s);

    return 0;
}