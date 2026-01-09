#include<bits/stdc++.h>
using namespace std;


int priority(string role){
    if(role=="rat") return 0;
    else if(role=="woman" || role=="child") return 1;
    else if(role=="man") return 2;
    else return 3;
}

int main(){
    int n;
    cin>>n;
    vector<string> ship(n+1);
    for(int i=0;i<=n;i++){
        getline(cin, ship[i]);
    }

    // for(int i=1;i<n+1;i++) cout<<ship[i];
    vector<pair<int, pair<int, string>>> detail(n);

    for(int i=1;i<=n;i++){
        int pos=ship[i].find(" ");

        string role=ship[i].substr(pos+1);
        string name=ship[i].substr(0, pos);

        detail[i-1]={priority(role),{i, name}};
    }
    
    sort(detail.begin(), detail.end());

    vector<string> ans(n);
    
    for(int i=0;i<n;i++){
        ans[i]=detail[i].second.second;
    }

    for(auto it: ans) cout<<it<<endl;
    return 0;
}