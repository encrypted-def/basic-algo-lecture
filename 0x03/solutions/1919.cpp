// Authored by : twinkite
// Co-authored by : -
// http://boj.kr/113a0c8415164751b8316d0dcc589658
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int res = 0;
  string s1, s2;
  int arr[2][26];
  fill(arr[0], arr[0]+26, 0);
  fill(arr[1], arr[1]+26, 0);
  cin>>s1>>s2;
  for(int i=0;i<s1.size();i++){
      arr[0][s1[i]-'a']++;
  }
  for(int i=0;i<s2.size();i++){
      arr[1][s2[i]-'a']++;
  }
  for(int i=0;i<26;i++){
      res+=abs(arr[0][i]-arr[1][i]);
  }
  cout<<res;
  return 0;
}