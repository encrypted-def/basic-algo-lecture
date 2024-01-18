// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/fc8f300d54f94c62a70da57ff910fb71
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int ans = 0;
int v;
vector<pair<int, int>> adj[100001];
int p[100001];

int dfs(int cur) {
  int first = 0;
  int second = 0;
  for (auto nxt : adj[cur]) {
    if (p[cur] == nxt.X) continue;
    p[nxt.X] = cur;
    int dist = dfs(nxt.X) + nxt.Y;
    if (dist > first) {
      second = first;
      first = dist;
    } else if (dist > second) {
      second = dist;
    }
  }
  ans = max(ans, first + second);
  return first;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v;
  for (int i = 1; i <= v; i++) {
    int a, b, c;
    cin >> a;
    while (true) {
      cin >> b;
      if (b == -1) break;
      cin >> c;
      adj[a].push_back({b, c});
    }
  }
  dfs(1);
  cout << ans;
}
/*
지름은 결국 한 점으로부터 가장 먼 두 자식까지의 거리의 합이 된다.
dfs(x)는 x를 root로 하는 서브트리에서 가장 먼 자식까지의 거리를 반환한다.
*/
