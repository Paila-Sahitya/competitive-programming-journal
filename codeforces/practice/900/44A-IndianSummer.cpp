#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<string, string>> leaves(n);

    for(int i=0;i<n;i++){
        cin>>leaves[i].first>>leaves[i].second;
    }

    set<pair<string, string>> st;
    for(int i=0;i<n;i++){
        st.insert(leaves[i]);
    }

    cout<<st.size();

    return 0;
}