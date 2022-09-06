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
// curr번 정점을 얼리어답터로 둘 때 / 두지 않을때에 대한 dp
int dp(int curr, bool isEarlyAdaptor) {
  if (state[curr][isEarlyAdaptor] != -1)
    return state[curr][isEarlyAdaptor];

  int val = 0;
  if (isEarlyAdaptor) // curr번 정점이 얼리어답터이면 자식은 얼리어답터이든 아니든 상관이 없으니 dp(nxt, false), dp(nxt, true) 중 최솟값을 더하면 됨
    for (int nxt : tree[curr])
      val += min(dp(nxt, false), dp(nxt, true));
  else
    for (int nxt : tree[curr])  // curr번 정점이 얼리어답터가 아니면 자식은 얼리어답터여야 하니 dp(nxt, true)를 더하면 됨
      val += dp(nxt, true);

  return state[curr][isEarlyAdaptor] = val + isEarlyAdaptor; // isEarlyAdaptor가 true인 경우 얼리어답터의 수를 1 증가시켜야 하기 때문
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
먼저 임의로 1번 정점을 루트로 정한 후 트리를 구성
state[node][isEarlyAdapter]
: 해당 node를 루트로 하는 서브트리에 대해, isEarlyAdapter=true일 경우 node가 얼리어답터일 때 필요한 최소 얼리 어답터의 수
isEarlyAdapter=false일 경우 node가 얼리어답터가 아닐 때 필요한 최소 얼리 어답터의 수
*/
