// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/dad5484ef3f3425fa58586f7684ed70e
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MX = 100'002;
const ll INF = 0x7f7f7f7f7f7f;

int n, m, k;
ll d[MX];
vector<pair<ll,int>> adj[MX];
priority_queue< pair<ll, int>,
                vector<pair<ll, int>>,
                greater<pair<ll, int>> > pq;

void solve(){
  while(!pq.empty()){
    int u, v;
    ll w, dw;
    tie(w, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      dw += w;
      if(dw >= d[v]) continue;
      d[v] = dw;
      pq.push({dw, v});
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  fill(d + 1, d + n + 1, INF);

  int u, v;
  ll w;
  while(m--){
    cin >> u >> v >> w;
    adj[v].push_back({w, u});
  }

  int ct;
  while(k--){
    cin >> ct;
    d[ct] = 0;
    pq.push({d[ct], ct});
  }

  solve();

  int cidx = max_element(d + 1, d + n + 1) - d;
  cout << cidx << '\n' << d[cidx];
}
/*
각 도시에서 면접장들로 향하는 최단거리를 계산하면
시간복잡도는 O(VElgE)가 되며, V와 E가 10^5 단위기 때문에
제한 시간 내로 풀리지 않습니다.

따라서 거꾸로 면접장들과 각 도시 사이의
최단거리를 구하는 풀이로 접근하였습니다.
이 경우 다익스트라 알고리즘을 한 번 사용하게 됩니다.

역으로 면접장에서 도시로 가야하기 때문에
간선을 입력받을 때 시작 정점과 끝 정점을 반대로 받습니다.

면접장이 있는 도시들은 거리를 0으로 설정하고
우선순위 큐에 넣습니다.

도시의 수가 10^5, 도로의 길이가 10^5이기 때문에
int 범위를 넘을 가능성이 있어
거리 계산 시에 long long 타입을 사용하였습니다.
*/