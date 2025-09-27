// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/e9299260ea9f422797254b913d7f0003
#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+5;
int n, d[mn], mincnt, root = 1;
bool flipped[mn];
vector<tuple<int, bool, int>> adj[mn]; // 간선을 {도착 정점 번호, 뒤집힌 간선인지의 여부, 간선의 인덱스} 형태로 저장

/*
d[i] = 다른 모든 정점에 도달 가능한 정점이 i번 정점이라고 했을 때 뒤집어야 하는 간선의 개수
     = i번 정점을 루트로 하고 모든 간선들이 부모에서 자식 방향으로 향하게 하여 만들어진 트리에서, 뒤집혀 있는 간선의 개수

c의 부모 p와 p-c를 잇는 간선 e에 대해, d[p]를 알고있을 때 d[c]가 어떻게 계산될지 생각해보면,
d[p]는 p를 루트로 하고 모든 간선이 아래로 향하게 만들어진 트리인데, 루트가 c로 바뀌면 c는 기존에도 c를 루트로 하던 서브트리와
그것을 제외한 p를 루트로 하는 서브트리를 자식으로 가지게 됩니다. 그런데 두 서브트리 모두 기존에도 간선이 아래로 향하게 만들어져 있기 때문에,
뒤집어야할지 말아야할지 고려해야하는 간선은 e뿐입니다.
만약 e가 p->c방향이라면 d[p]는 e를 포함하지 않은 개수이고, d[c]는 e를 뒤집어서 계산해야하기 때문에 d[c] = d[p] + 1이고,
c->p방향이라면 d[p]는 e를 포함한 개수이고 d[c]는 e를 뒤집을 필요가 없으므로 d[c] = d[p] - 1입니다.

dfs(1)로 d[1]을 계산하고, bfs(1)에서 d[1]로부터 다른 모든 정점들의 d값을 계산해나갑니다.
*/
int dfs(int par, int cur){
  d[cur] = 0;
  for(auto nxt : adj[cur]){
    int ch, isflip, idx;
    tie(ch, isflip, idx) = nxt;
    if(ch == par) continue;
    d[cur] += dfs(cur, ch) + isflip;
  }
  return d[cur];
}

void bfs(int start){
  queue<pair<int, int>> q;
  q.push({-1, start});
  while(!q.empty()){
    int par, cur;
    tie(par, cur) = q.front(); q.pop();
    if(d[cur] < mincnt){
      mincnt = d[cur];
      root = cur;
    }
    for(auto nxt : adj[cur]){
      int ch, isflip, idx;
      tie(ch, isflip, idx) = nxt;
      if(ch == par) continue;
      d[ch] = (isflip ? d[cur]-1 : d[cur]+1);
      q.push({cur, ch});
    }
  }
}

void chkflip(){
  queue<pair<int, int>> q;
  q.push({-1, root});
  while(!q.empty()){
    int par, cur;
    tie(par, cur) = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      int ch, isflip, idx;
      tie(ch, isflip, idx) = nxt;
      if(ch == par) continue;
      flipped[idx] = isflip;
      q.push({cur, ch});
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; ++i){
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, 0, i});
    adj[v].push_back({u, 1, i});
  }

  mincnt = dfs(-1, 1);
  bfs(1);
  chkflip();
  for(int i = 0; i < n-1; ++i)
    cout << flipped[i];
}
