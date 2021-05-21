// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/62b94c1ad9254f87a1f6e37323f2c5bf
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll d[100][2];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  d[1][1] = 1LL;
  for(int i = 2; i <= n; ++i){
    d[i][0] = d[i-1][0] + d[i-1][1];
    d[i][1] = d[i-1][0];
  }
  cout << d[n][0] + d[n][1];
}
