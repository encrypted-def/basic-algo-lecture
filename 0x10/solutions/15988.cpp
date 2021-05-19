// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/945b646aaf504415a5efd80a21dff6b7
#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000010];
int mod = 1e9 + 9;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  d[1] = 1; d[2] = 2; d[3] = 4;
  for(int i = 4; i <= 1000000; ++i)
    for(int j = 1; j <= 3; ++j)
      d[i] = (d[i] + d[i-j]) % mod;
  
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    cout << d[n] << '\n';
  }
}
