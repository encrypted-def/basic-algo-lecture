// Authored by : Joshua-Shin
// Co-authored by : -
// http://boj.kr/fc8c44a625de4949b552c8f1dbb0c0a8
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100001];
bool check[100001];
int p[100001];
int bfs(int x) {
  int cnt = 0;
  queue<int> q;
  check[x] = true;
  q.push(x);
  while(!q.empty()) {
    x = q.front();
    q.pop();
    for(auto nx: adj[x]) {
      if(nx == p[x]) continue;
      if(check[nx]) {
        cnt++;
        continue;
      }
      check[nx] = true;
      p[nx] = x;
      q.push(nx);
    }
  }
  return cnt/2;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  memset(check, false, sizeof(check));
  int groupCnt = 0;
  int cutCnt = 0;
  for(int i = 1; i<=n; i++) {
    if(check[i]==false) {
      groupCnt++;
      cutCnt += bfs(i);
    }
  }
  cout <<  groupCnt -1 + cutCnt << '\n';
  return 0;
}
