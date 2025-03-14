// http://boj.kr/516ca512ed9d4b5bb32b28ab50bbf349
#include <bits/stdc++.h>
using namespace std;

int d[10005];
int mod = 10007;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  for(int i = 3; i <= n; i++) d[i] = (d[i-1]+d[i-2])%mod;
  cout << d[n];
}
