// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/e8bb71d963ad4c0e87544b09d676ad8e
#include <bits/stdc++.h>
using namespace std;
int d[1001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;++i) cin>>d[i];
  
  for(int i=1;i<=n;++i) {
    for(int j=1;j<i;++j) {
      d[i] = max(d[i-j] + d[j], d[i]);
    }
  }
  cout << d[n];
}
