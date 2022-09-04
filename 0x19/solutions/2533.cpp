// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/530322f39b5840d99f9e2bd7ea3b5c47
#include <bits/stdc++.h>
using namespace std;

const int MXN = 1'000'010;
int N, u, v;
vector<int> adj[MXN], tree[MXN], state[MXN];
void mktree(int curr, int prev) {
  for (int nxt : adj[curr]) {
    if (nxt == prev) continue;
    tree[curr].push_back(nxt);
    mktree(nxt, curr);
  }
}
int dp(int curr, bool isEarlyAdaptor) {
  if (state[curr][isEarlyAdaptor] != -1)
    return state[curr][isEarlyAdaptor];

  int val = 0;
  if (isEarlyAdaptor)
    for (int nxt : tree[curr])
      val += min(dp(nxt, false), dp(nxt, true));
  else
    for (int nxt : tree[curr])
      val += dp(nxt, true);

  return state[curr][isEarlyAdaptor] = val + isEarlyAdaptor;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    state[i].push_back(-1);
    state[i].push_back(-1);
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  mktree(1, -1);
  cout << min(dp(1, false), dp(1, true));
}
/*
state[node][isEarlyAdapter]
: 해당 node가 isEarlyAdapter인 경우에 필요한 최소 얼리 어답터의 수
*/