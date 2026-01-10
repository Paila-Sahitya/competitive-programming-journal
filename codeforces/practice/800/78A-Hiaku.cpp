#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
   string s="aeiou";
   if(s.find(ch)<s.size()) return true;
   return false;
}

int haiku(string s){
   int cnt=0;
   for(int i=0;i<s.size();i++){
      if(isVowel(s[i])) cnt++;
   }
   // cout<<cnt<<endl;
   return cnt;
}
int main(){

   vector<string> poetry(3);
   for(int i=0;i<3;i++){
      getline(cin, poetry[i]);
   }
   
   
   if(haiku(poetry[0])==5 && haiku(poetry[1])==7 && haiku(poetry[2])==5){
      cout<<"YES";
   }
   else cout<<"NO";

   return 0;
}