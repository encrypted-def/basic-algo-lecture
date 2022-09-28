// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/e62cb91c4cb1406faa70bd2c3cab0eeb
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f;

ll c, d[100002];
int n, m, st, en;

vector<pair<ll, int>> adj[100002];
priority_queue< tuple<ll, ll, int>, 
                vector<tuple<ll, ll, int>>,
                greater<tuple<ll, ll, int>> > pq;

ll solve(){
  fill(d, d + n + 1, INF);
  d[st] = 0;
  pq.push({d[st], 0, st});
  while(!pq.empty()){
    int u, v;
    ll w, dw, tc;
    tie(w, tc, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      if(tc + dw > c) continue;
      dw = max(dw, w);
      if(dw >= d[v]) continue;
      d[v] = dw;
      pq.push({dw, tc + dw, v});
    }
  }
  if(d[en] == INF) d[en] = -1;
  return d[en];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> st >> en >> c;

  int u, v; ll w;
  while(m--){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  cout << solve();
}
/*
지나는 골목의 요금 중 최댓값을 w라 하고,
이 w를 최소로 만드는 다익스트라 알고리즘을 사용하자.

기본적인 다익스트라 알고리즘 틀을 기준으로
이 문제에서 특별히 고려할 내용들만 서술하겠다.

사용할 우선순위 큐에는 튜플을 담으며,
튜플의 첫번째 변수로 w를 저장한다.
두번째 변수로 현재까지 지출한 비용을 저장한다.

우선순위 큐에서 꺼낸 원소가 26번째 줄 조건을 만족하여
다음 정점이 결정되었다 하자.
그 정점으로 가는 간선에서 추가되는 비용이
총 비용 제한값 c를 넘으면 우선순위 큐에 넣지 않는다.
또한 우선순위 큐의 w값과 이번에 선택한 간선의 코스트 중
큰 값을 우선순위 큐에 저장한다.

위같은 고려사항을 추가하여 다익스트라 알고리즘을 적용한다.
과정을 반복하다 우선순위 큐가 비면 루프를 끝내고
최단거리 테이블의 en번째 원소를 반환한다.

C가 최대 10^14이며, 골목 별 수금액 최댓값이 10^9,
정점 개수가 최대 10^5개이므로
가중치로 들어가는 변수는 long long 타입이어야 하고,
최단거리 테이블을 초기화할 무한대 값(INF) 역시
이를 고려해 충분히 큰 값을 적용해야 한다.
*/