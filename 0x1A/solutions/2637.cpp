// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/75874968f2df40deb138395b97610bb3
#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

vector<pair<int, int>> req[MX + 2]; // req[cur] = {nxt, c};
int cnt[MX + 2], ind[MX + 2];
bool isbase[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(isbase, isbase + MX + 1, 1);

  int n, m; cin >> n >> m;
  while(m--) {
    int x, y, k;
    cin >> x >> y >> k;
    isbase[x] = 0;
    req[x].push_back({y, k});
    ind[y]++;
  }

  queue<int> q;
  q.push(n);
  cnt[n] = 1;

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(auto [nxt, c] : req[cur]) {
      cnt[nxt] += c * cnt[cur];
      ind[nxt]--;
      if(ind[nxt] == 0) q.push(nxt);
    }
  }

  for(int i = 1; i <= n; i++)
    if(isbase[i]) cout << i << ' ' << cnt[i] << '\n';
}