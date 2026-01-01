// A. Triangle

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums(4);
    for(int i=0;i<4;i++){
        cin>>nums[i];
    }
    bool triangle=false, segment=false;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            for(int k=j+1;k<4;k++){
                vector<int> sides={nums[i], nums[j], nums[k]};
                sort(sides.begin(), sides.end());
                if(sides[0]+sides[1]>sides[2]){
                    triangle=true;
                }
                else if(sides[0]+sides[1]==sides[2]){
                    segment =true;
                }
            }
        }
    }
    if(triangle) cout<<"TRIANGLE";
    else if(segment) cout<<"SEGMENT";
    else cout<<"IMPOSSIBLE";

    return 0;
}