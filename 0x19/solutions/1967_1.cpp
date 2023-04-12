// Authored by : syoh0708
// Co-authored by : -
// http://boj.kr/506e6d8e06d4409c9f52188587ce06f8
#include <bits/stdc++.h>

using namespace std;

int n, diam;
vector<pair<int, int>> e[10005];

pair<int, int> dfs(int cur) {
  int x = 0, y = 0;
  vector<int> dist;

  for (auto nxt : e[cur]) {
    pair<int, int> d = dfs(nxt.first);
    dist.push_back(d.first + nxt.second);
  }

  sort(dist.begin(), dist.end(), greater<int>());
  if (dist.size() > 0) x = dist[0];
  if (dist.size() > 1) y = dist[1];
  diam = max(diam, x + y);

  return {x, y};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v, d; cin >> u >> v >> d;
        
    e[u].push_back({v, d});
  }

  dfs(1);

  cout << diam;
}

/**
 * 트리의 지름을 그렸을 때 가장 루트에 가까운 노드를 a라 하자(문제의 예제에서 3번 노드)
 * 노드 a 입장에서 봤을 때 a의 자식 노드 c_i에 대해서 a에서 c_i를 지나는 리프까지의 최대 거리를 d_i라고 하면
 * 트리의 지름은 d_i 중 가장 긴 원소와 과 두 번째로 긴 원소를 더한 것과 같다.
*/
