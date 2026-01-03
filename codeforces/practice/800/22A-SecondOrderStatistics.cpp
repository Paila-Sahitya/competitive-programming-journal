#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }
    vector<int> distinct;
    for(auto it: st){
        distinct.push_back(it);
    }
    if(distinct.size()>1) cout<<distinct[1];
    else cout<<"NO";

    return 0;
}