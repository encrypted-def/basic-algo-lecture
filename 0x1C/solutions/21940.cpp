// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/631b99a74c034c418ae2c812f588e52e
#include <bits/stdc++.h>
using namespace std;

const int INF = 987987987;

int n, m, f;
int c[202];
int d[202][202];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    fill(d[i], d[i] + n + 1, INF);
    d[i][i] = 0;
  }

  int x, y, cost;
  while(m--) {
    cin >> x >> y >> cost;
    d[x][y] = min(d[x][y], cost);
  }
  cin >> f;
  for(int ci = 1; ci <= f; ci++) {
    cin >> x;
    c[ci] = x;
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

  vector<pair<int,int>> v;
  for(int i = 1; i <= n; i++) {
    int mx = 0;
    for(int ci = 1; ci <= f; ci++)
      mx = max(mx, d[i][c[ci]] + d[c[ci]][i]);
    v.push_back({mx, i});
  }
  sort(v.begin(), v.end());

  int mn = v[0].first;
  for(auto cur : v) {
    if(mn < cur.first) break;
    cout << cur.second << ' ';
  }
}