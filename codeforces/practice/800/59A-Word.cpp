#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int ucnt=0;
    int lcnt=0;

    string up="", low="";
    for(auto it: s){
        if(it>='A' && it<='Z'){
            ucnt++;
            up+=it;
            low+=(it+'a'-'A');
        }
        else{
            lcnt++;
            up+=(it-'a'+'A');
            low+=it;
        }
    }
    if(lcnt>=ucnt) cout<<low;
    else cout<<up;

    return 0;
}