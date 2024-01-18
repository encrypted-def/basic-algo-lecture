// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/4bf034b6c2d945d29716a5483d78bb28
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
vector<pair<int, int>> adj[1001];
bool chk[1001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int c;
      cin >> c;
      if (i >= j) continue;
      adj[i].push_back({c, j});
      adj[j].push_back({c, i});
    }
  }
  int cnt = 0;
  long long ans = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  chk[1] = true;
  for (auto nxt : adj[1]) pq.push(nxt);
  while (cnt < n - 1) {
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
