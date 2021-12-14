// Authored by : erolf0123
// Co-authored by : -
// http://boj.kr/3914322728a54b0d8ab87da84db0354b
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector < int>> v(n + m + 4);
  for(int i = 1; i <= m; i++)
    for(int j = 1, x; j <= k; j++) {
      cin >> x;
      v[n + i].push_back(x);
      v[x].push_back(n + i);
    }
  queue<int> q;
  q.push(1);
  vector<int> dist(n + m + 4);
  dist[1] = 1;
  while(q.size()) {
    int here = q.front();
    q.pop();
    for(int next: v[here])
      if(!dist[next]) {
        q.push(next);
        dist[next] = dist[here] + (next <= n);
      }
  }
  cout << (dist[n] ? : -1);
}