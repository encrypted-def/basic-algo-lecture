// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/423861969c3b470a932358dfbf516c11
#include <bits/stdc++.h>
using namespace std;

const int MXN = 100'010;
bool vis[MXN];
int mxCost, mxNode;
vector<pair<int, int>> adj[MXN];
void dfs(int cur, int dist) {
  if (mxCost < dist) {
    mxNode = cur;
    mxCost = dist;
  }
  for (auto [nxtDist, nxt] : adj[cur]) {
    if (vis[nxt]) continue;
    vis[nxt] = true;
    dfs(nxt, dist + nxtDist);
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, u, v, c;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> c;
    adj[u].push_back({c, v});
    adj[v].push_back({c, u});
  }
  vis[1] = true;
  dfs(1, 0);
  fill(vis, vis + MXN, false);
  vis[mxNode] = true;
  dfs(mxNode, 0);
  cout << mxCost;
}
/*
트리의 지름을 찾으려면 아무 한 점에서 제일 멀리 간 다음,
그 점에서 제일 멀리 있는 점까지의 거리를 재면 됩니다.
*/