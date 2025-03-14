// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/85b770d684b942b6994994606010adc0
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MX = 10;

int n, ans = INF;
int viscnt;

int po[MX + 2];
bool vis[MX + 2];

vector<bool> comb;
vector<int> adj[MX + 2];

queue<int> q;

void bfs(int st) {
  bool code = comb[st];
  vis[st] = 1;
  viscnt++;
  q.push(st);

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(vis[nxt] || comb[nxt] != code) continue;
      vis[nxt] = 1;
      viscnt++;
      q.push(nxt);
    }
  }
}

void solve(int m) {
  fill(comb.begin(), comb.end(), 0);

  for(int i = n - m; i < n; i++)
    comb[i] = 1;
  
  do {
    viscnt = 0;
    fill(vis, vis + n, 0);

    for(int i = 0; i < n; i++)
      if(!comb[i]) { bfs(i); break; }
    for(int i = 0; i < n; i++)
      if(comb[i]) { bfs(i); break; }

    if(viscnt != n) continue;

    int tmp = 0;
    for(int i = 0; i < n; i++) {
      if(comb[i]) tmp += po[i];
      else tmp -= po[i];
    }
    tmp = abs(tmp);
    ans = min(tmp, ans);
  } while(next_permutation(comb.begin(), comb.end()));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> po[i];
  for(int i = 0; i < n; i++) {
    int m; cin >> m;
    while(m--) {
      int x; cin >> x;
      adj[i].push_back(x - 1);
    }
  }

  comb.resize(n);
  for(int i = 1; i <= n / 2; i++)
    solve(i);
  if(ans == INF) ans = -1;
  cout << ans;
}
/*
next_permutation을 활용해 comb가 1인 구역을 하나씩 늘린다.
이로써 n개 구역 중 1개 구역부터 n/2개 구역까지 선택하며 선거구를 구성한다.
구역이 속한 선거구는 comb 값에 따라 구분한다.

이같이 구현하는 경우, 0011과 1100을 다른 경우로 판단해 중복 연산이 발생한다.
그러나, n이 가장 클 때인 10개 구역에 대해서
1명부터 5명씩 팀을 나누는 경우가 10C1 + 10C2 + 10C3 + 10C4 + 10C5이고
이들은 10 + 45 + 120 + 210 + 252 = 637이기 때문에,
더 효율적으로 팀을 나눌 필요는 없다고 판단하였다.

문제를 그래프로 구현했다.
문제의 구역 번호는 1-indexed지만, 편의상 0-indexed로 바꿔 구현하였다(69-75번째 줄).

구역 중 comb 값이 0인 경우와 1인 경우를 하나씩 찾아 bfs를 수행(45-48번째 줄)한다.
이때, 인접한 구역 중 동일 선거구에 속한 구역만 방문하고 큐에 넣는다(26-31번째 줄).

만약 comb 값이 0인 구역과 1인 구역에 대한 bfs를 마친 뒤에도 
방문횟수를 세는 viscnt 변수가 n에 도달하지 못했다면,
이는 인접하지 않은 구역이 있는 것이므로
인구 차이를 계산하지 않고 다음 경우로 넘어간다.

이같이 계산된 최솟값을 답으로 출력한다.
만약, 모든 경우에 대해 선거구가 나눠지지 않는다면
ans은 갱신되지 않아 INF이므로, 이 경우 -1을 출력한다.
*/