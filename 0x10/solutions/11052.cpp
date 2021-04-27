// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/42d1214f12244dad978c1b1ec82679f2
#include <bits/stdc++.h>
using namespace std;

int a[1001];
int d[1001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    d[i] = a[i];
  }
  for(int i=1;i<=n;++i) {
    for(int j=1;j<i;++j) {
      d[i] = max(d[i-j] + d[j], d[i]);
    }
  }
  cout << d[n];
}
