#include<bits/stdc++.h>
using namespace std;

//matchboxes of same size
int main(){

    int k, n;
    cin>>k>>n;
    //container ->matchboxes, matches
    vector<pair<int, int>>container(n);
    for(int i=0;i<n;i++){
        cin>>container[i].first>>container[i].second;
    }
    //choose k matchboxes

    priority_queue<pair<int, int>> pq;
    //maxheap 

    for(auto it: container){
        pq.push({it.second, it.first});
    }
    
    int maxMatches=0;
    int count=k;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int matches=it.first;
        int box=it.second;
        if(count-box>=0){
            maxMatches+=matches*box;
            count-=box;
        }
        else{
            int rem=count;
            count=0;
            maxMatches+=rem*matches;
        }
        if(count==0) break;

    }
    cout<<maxMatches;

    return 0;
}