// Authored by : Joshua-Shin
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/03ccb739558649f5b0ecfbc2e5caaec4
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
bool vis[100001];

void dfs(int cur){
  if(vis[cur]) return;
  vis[cur] = true;
  for(auto nxt : adj[cur])
    dfs(nxt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int groupcnt = 0;
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    dfs(i);
    groupcnt++;
  }
  cout << (groupcnt-1) + (m+groupcnt-1)-(n-1);
}

/*
우선 connected component의 개수(=groupcnt)를 셉니다. groupcnt-1개의 간선을 추가해 주어진 그래프를 연결 그래프로 만듭니다.
현재 그래프에는 m+groupcnt-1개의 간선이 있고 트리는 n-1개의 간선이 있기 때문에 (m+groupcnt-1)-(n-1)개의 간선을
제거해야 합니다. 최종적으로 답은 (groupcnt-1) + (m+groupcnt-1)-(n-1) 입니다.
*/
