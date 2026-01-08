#include<bits/stdc++.h>
using namespace std;

string v[]={"rock", "paper", "scissors"};
void gameRules(vector<string> vals){
    int winner=-1;
    for(int i=0;i<3;i++){
        string choice=vals[i];
        string req="";
        for(int j=0;j<3;j++){
            if(choice==v[j]){
                req=v[(3+j-1)%3];
            }
        }
        if(vals[(i+1)%3]==req && vals[(i+2)%3]==req) winner=i;
    }
    if(winner==-1) cout<<"?";
    else if(winner==0) cout<<"F";
    else if(winner==1) cout<<"M";
    else cout<<"S";
}
int main(){
    
    string f, m, s;
    cin>>f>>m>>s;
    vector<string> val={f, m, s};
    gameRules(val);
    return 0;
}