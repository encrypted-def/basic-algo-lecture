// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/99a5276b487143f2995ef461b49edc1c
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10010], d[10010];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  d[1] = a[1]; d[2] = a[1] + a[2];
  for(int i = 3; i <= n; ++i)
    d[i] = max({d[i-1], d[i-2] + a[i], d[i-3] + a[i-1] + a[i]});
  cout << d[n];
}
