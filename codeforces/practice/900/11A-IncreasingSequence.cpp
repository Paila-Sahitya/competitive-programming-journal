// A. Increasing Sequence

#include<bits/stdc++.h>
using namespace std;

int IncSequence(vector<int> &nums, int d){
    int n=nums.size();
    if(n<2) return 0;
    int moves=0;
    for(int i=1;i<n;i++){
        if(nums[i]>nums[i-1]) continue;
        int diff=nums[i-1]-nums[i];
        int req=diff/d + 1;
        // cout<<diff<<" "<<req<<" "<<nums[i]<<" ";
        nums[i]=nums[i]+req*d;
        // cout<<" : "<<nums[i]<<endl;
        moves+=req;
    }
    return moves;
}


int main(){
    int n, d;
    cin>>n>>d;
    vector<int> seq(n);
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }

    cout<<IncSequence(seq, d);
    return 0;
}