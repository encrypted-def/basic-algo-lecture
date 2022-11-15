// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/68fa2a092ac84abe8985db26901b7544
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> hv[101], li[101];
bool vis[101];

bool solve(int st, vector<int> (&adj)[]) {
  fill(vis, vis + n + 1, 0);
  queue<int> q;

  q.push(st);
  vis[st] = 1;

  int cnt = 0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = 1;
      cnt++;
    }
  }
  return cnt >= (n + 1)/2;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    hv[u].push_back(v);
    li[v].push_back(u);
  }

  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans += (solve(i, hv) || solve(i, li));
  cout << ans;
}
/*
그래프 입력으로 구슬 u와 구슬 v의 관계를 받는다.
- hv[u] = v: u는 v보다 무겁다.
- li[v] = u: v는 u보다 가볍다.
따라서 인접 리스트를 입력 받을 때 39-40번째 줄과 같이 저장한다.

44-45번째 줄을 통해 1부터 n까지 구슬에 대해 solve를 수행한다.
그 중 임의의 구슬 i에 대해 수행하는 경우를 아래에 서술하겠다.

solve(i, hv)는 구슬 i보다 무거운 구슬을 센다.
구슬 i보다 무거운 구슬 수가 전체 구슬 개수의 절반을 넘으면
구슬 i는 전체 구슬 중에서 무게 순으로 중간에 위치할 수 없으므로
정답 개수를 더한다.

solve(i, li)는 구슬 i보다 가벼운 구슬을 센다.
구슬 i보다 가벼운 구슬 수가 전체 구슬 개수의 절반을 넘으면
구슬 i는 전체 구슬 중에서 무게 순으로 중간에 위치할 수 없으므로
마찬가지로 정답 개수를 더한다.
*/