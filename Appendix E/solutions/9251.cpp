// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/cf49db3b3f394eb192a482da5f7a8f84
#include <bits/stdc++.h>
using namespace std;

string a, b;
int n, m;
int d[1005][1005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  n = a.size();
  m = b.size();

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1])
        d[i][j] = d[i-1][j-1] + 1;
      d[i][j] = max({d[i][j], d[i-1][j], d[i][j-1]});
    }
  }
  cout << d[n][m];
}
