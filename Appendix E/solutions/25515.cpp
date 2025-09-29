// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/190a0fda546b4e47971e626d4a329620
#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5 + 5;
int n, val[mn];
vector<int> adj[mn];

/*
dfs(cur) = 정점 cur을 방문할 때 정수 합의 최댓값
         = cur의 모든 자식 ch에 대해 max(0, dfs(cur, ch)) 값들의 합 + 정점 cur에 적힌 정수
*/
long long dfs(int par, int cur){
  long long res = val[cur];
  for(int nxt : adj[cur]){
    if(nxt == par) continue;
    res += max(1LL*0, dfs(cur, nxt));
  }
  return res;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; ++i){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 0; i < n; ++i)
    cin >> val[i];

  cout << dfs(-1, 0);
}
