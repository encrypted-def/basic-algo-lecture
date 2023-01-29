// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/7ea13fdf01044049950a56fec972210c
#include <bits/stdc++.h>
using namespace std;

const int MX = 300;
const int INF = 0x3f3f3f3f;

int h[MX + 2][MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, t;
  cin >> n >> m >> t;

  for(int i = 1; i <= n; i++)
    fill(h[i], h[i] + MX + 1, INF);

  for(int i = 1; i <= n; i++)
    h[i][i] = 0;

  while(m--) {
    int u, v, height; 
    cin >> u >> v >> height;
    h[u][v] = height;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        h[i][j] = min(h[i][j], max(h[i][k], h[k][j]));

  while(t--) {
    int st, en;
    cin >> st >> en;
    if(h[st][en] == INF) cout << -1 << '\n';
    else cout << h[st][en] << '\n';
  }
}
/*
현재까지 계산된 i에서 j로 가는 길목의 허들 높이를 h[i][j]라 하자.

플로이드 알고리즘을 통해 N개 노드를 경유하면서
h[i][j]를 아래 두 값 중 작은 값으로 갱신한다(31번째 줄).
  1. h[i][j]의 현재 값
  2. i -> k -> j 경로로 갈 때의 길목 상 최대 허들 높이
    - h[i][k], h[k][j] 중 큰 값
*/