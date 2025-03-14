// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/86f37422923c4e8299ab236d6bd3ccb7
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;

  int ind[n + 2] = {};
  vector<int> adj[n + 2];
  priority_queue< int,
      vector<int>,
      greater<int> > pq;

  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    ind[v]++;
  }
  for(int i = 1; i <= n; i++)
    if(!ind[i]) pq.push(i);

  while(!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    cout << cur << ' ';
    for(int nxt : adj[cur]) {
      ind[nxt]--;
      if(!ind[nxt]) pq.push(nxt);
    }
  }
}
/*
최소힙을 활용하여 더 쉬운 문제(더 낮은 번호)를
먼저 풀도록 합니다.
*/