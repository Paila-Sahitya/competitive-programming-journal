#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    int p1, p2, p3, t1, t2;
    cin>>n>>p1>>p2>>p3>>t1>>t2;

    vector<pair<int, int>> time(n);
    for(int i=0;i<n;i++){
        cin>>time[i].first>>time[i].second;
    }
    int l1=time[0].first;
    int rn=time[n-1].second;
    int power=0;
    for(int i=0;i<n;i++){
        int gap=(time[i].first-l1);
        int work=time[i].second-time[i].first;

        int run=work*p1;
        if(gap-t1>=0) {
            run+=t1*p1;
            gap=gap-t1;
        }
        else{
            run+=gap*p1;
            gap=0;
        }
        int safe=0;
        if(gap-t2>=0){
            run+=t2*p2;
            gap=gap-t2;
        }
        else{
            run+=gap*p2;
            gap=0;
        }
        int off=gap*p3;
        // cout<<run<<" "<<safe<<" "<<off<<endl;
        power+=run+safe+off;
        l1=time[i].second;
    }
    cout<<power;


    return 0;
}