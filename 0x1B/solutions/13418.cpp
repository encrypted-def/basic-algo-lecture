// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/c90f2910a65f4ad1aa7542580caecd23
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

vector<tuple<int, int, int>> e;
int p[MX + 2], ans;
int n, m;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return 0;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

void solve(bool is_max_calc) {
  int sum = 0, cnt = 0;
  fill(p, p + MX + 2, -1);
  for(auto [cost, u, v] : e) {
    if(!is_diff_group(u, v)) continue;
    cnt++;
    sum += cost;
    if(cnt == n) break;
  }
  if(is_max_calc) ans += sum * sum;
  else ans -= sum * sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  m++;
  
  while(m--) {
    int u, v; bool cost;
    cin >> u >> v >> cost;
    e.push_back({!cost, u, v});
  }

  sort(e.begin(), e.end());
  solve(0);

  sort(e.rbegin(), e.rend());
  solve(1);

  cout << ans;
}
/*
편의상 간선 가중치의 합이 최대인 신장 트리는 최대 신장 트리라고 하겠습니다.

위 코드는 최소 신장 트리와 최대 신장 트리의 간선 가중치 합을 구한 뒤,
둘을 제곱한 값의 차이를 구하는 풀이입니다.

0번부터 n번까지 정점이 있기 때문에 총 n + 1개의 정점이 있으며,
신장 트리의 간선 수는 n개가 되어야 합니다.
따라서 cnt가 n이 될 때 for문을 끝냅니다(34번째 줄).

오르막길의 비용이 1, 내리막길의 비용이 0이 되도록 간선을 입력받습니다(50번째 줄).
이에 대한 최소/최대 신장 트리를 만듭니다.

최소/최대 신장 트리의 가중치 합은 크루스칼 알고리즘으로 구합니다.
가중치 합의 최솟값은 최소 신장 트리를 구하는 과정에서 얻을 수 있습니다.
가중치 합의 최댓값은 최대 신장 트리를 구하는 과정에서 얻을 수 있습니다.

최대 신장 트리는 최소 신장 트리의 경우와 반대로
간선 비용을 내림차순으로 정렬한 뒤
비용이 큰 간선부터 확인하며 신장 트리를 구성함으로써 얻게 됩니다.
*/