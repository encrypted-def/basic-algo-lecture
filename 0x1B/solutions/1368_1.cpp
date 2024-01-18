// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/aca5c2d5eed04bc1aac87a0d4bd1d674
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
vector<pair<int, int>> adj[100001];
bool chk[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    adj[i].push_back({w, 0});
    adj[0].push_back({w, i});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int p;
      cin >> p;
      if (i >= j) continue;
      adj[i].push_back({p, j});
      adj[j].push_back({p, i});
    }
  }
  int cnt = 0;
  int ans = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  chk[0] = true;
  for (auto nxt : adj[0]) pq.push(nxt);
  while (cnt < n) {
    auto cur = pq.top();
    pq.pop();
    if (chk[cur.Y]) continue;
    ans += cur.X;
    chk[cur.Y] = true;
    cnt++;
    for (auto nxt : adj[cur.Y])
      if (!chk[nxt.Y]) pq.push(nxt);
  }
  cout << ans;
}
