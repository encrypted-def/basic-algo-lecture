// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/4ec72033f25343b98b2cc89db2c9b0ac
#include <bits/stdc++.h>
using namespace std;

const int mn = 1005;
int n, m, d[mn];
vector<int> res;
vector<pair<int, int>> adj[mn]; // {도착 정점 번호, 가중치} 형태로 저장

/*
구현의 편의를 위해 시작하는 정점은 1로 유지하되, 마지막에 다시 돌아오는 정점은 가상의 노드 0으로 생각하였습니다.
d[i] = i번 정점에서부터 0번 정점까지 이동할 때 얻을 수 있는 최대 점수, 최종 정답 = d[1]
     = i번 정점에서 이동할 수 있는 바로 다음 정점들의 d값 중 최대 + 그 정점으로의 가중치
*/
int dfs(int cur){
  if(d[cur] != -1) return d[cur];
  d[cur] = 0;
  for(auto nxt : adj[cur])
    d[cur] = max(d[cur], dfs(nxt.first) + nxt.second);
  return d[cur];
}

// 역추적을 위해 cur번 정점에 대하여 다음으로 이동할 정점인 nxt_node를 결정하는 과정을 재귀적으로 수행
void btrace(int cur){
  res.push_back(cur);
  int mx = 0, nxt_node = 0;
  for(auto nxt : adj[cur]){
    if(d[nxt.first] + nxt.second <= mx) continue;
    mx = d[nxt.first] + nxt.second;
    nxt_node = nxt.first;
  }
  if(nxt_node == 0){
    res.push_back(1);
    return;
  }
  btrace(nxt_node);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(d, d+n+1, -1);
  while(m--){
    int p, q, r;
    cin >> p >> q >> r;
    // 도착하는 정점이 1일 경우 0으로 치환
    if(q == 1) q = 0;
    adj[p].push_back({q, r});
  }

  cout << dfs(1) << '\n';
  btrace(1);
  for(int i : res)
    cout << i << ' ';
}
