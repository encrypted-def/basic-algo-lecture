// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/9eab1f0076b4447fb0b9b5dda85660c3
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10010], d[10010][3];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  d[1][1] = a[1];
  for(int i = 2; i <= n; ++i){
    d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
    d[i][1] = d[i-1][0] + a[i];
    d[i][2] = d[i-1][1] + a[i];
  }
  cout << max({d[n][0], d[n][1], d[n][2]});
}
