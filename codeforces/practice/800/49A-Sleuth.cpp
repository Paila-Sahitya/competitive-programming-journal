#include<bits/stdc++.h>
using namespace std;

bool vowelCheck(char ch){
    if(ch>='A' && ch<='Z') ch=ch+('a'-'A');
    return (ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' || ch=='y');
}
int main(){
    string str;
    getline(cin, str);

    int n=str.size();
    int i=n-1;
    bool found=false;
    while(i>=0){
        char val=str[i];
        if(val!=' ' && val!='?'){
            found=vowelCheck(val);
            break;
        }
        i--;
    }
    if(found) cout<<"YES";
    else cout<<"NO";
    return 0;
}