#include<bits/stdc++.h>
using namespace std;

void minUnit(vector<int> &heights){
    int n=heights.size();
    int mini=abs(heights[0]-heights[1]);
    int ind1=0, ind2=1;
    for(int i=0;i<n;i++){
        int ind=(i+1)%n;
        if(abs(heights[i]-heights[ind])<mini){
            mini=abs(heights[i]-heights[ind]);
            ind1=i, ind2=ind;
        }
    }
    cout<<ind1+1<<" "<<ind2+1;
}
int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    minUnit(heights);

    return 0;
}