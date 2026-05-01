#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, l, r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    vector<vector<int>> hash(26);
    long long cnt=0;
    for(int i=0;i<n;i++){
        hash[s[i]-'a'].push_back(i);
        int d=s[i]-'a';
        auto &temp=hash[d];

        // for(int j=0;j<hash[d].size();j++){
        //     int diff=i-hash[d][j];
        //     if(diff>=l && diff<=r) cnt++;
        // }
        int ll=i-r;
        int rr=i-l;
        auto lb=lower_bound(temp.begin(), temp.end(), ll);
        auto ub=upper_bound(temp.begin(), temp.end(), rr);
        cnt+=ub-lb;
    }
    cout<<cnt<<"\n";


    return 0;
}