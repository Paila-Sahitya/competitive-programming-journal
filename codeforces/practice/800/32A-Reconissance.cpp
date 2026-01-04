#include<bits/stdc++.h>
using namespace std;

int reconissanceUnit(vector<int> &heights, int &d){
    int n=heights.size();
    int cnt=0;
    sort(heights.begin(), heights.end());

    for(int i=0;i<n-1;i++){
        int h1=heights[i];
        int j=i+1;
        while(j<n){
            // cout<<heights[i]<<" "<<heights[j]<<endl;
            if(heights[j]-h1>d) break;
            cnt+=2;
            j++;
        }
    }
    return cnt;
}

int main(){
    int n, d;
    cin>>n>>d;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    cout<<reconissanceUnit(heights, d);

    return 0;
}