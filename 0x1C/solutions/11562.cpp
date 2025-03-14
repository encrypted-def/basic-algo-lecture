// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/a8f73829630741d9a8dc21315b974800
#include <bits/stdc++.h>
using namespace std;

const int INF = 987987987;

int n, m, u, v;
bool b;
int d[252][252];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  while(m--){
    cin >> u >> v >> b;
    d[u][v] = 0;
    d[v][u] = !b;
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

  cin >> m;
  while(m--){
    cin >> u >> v;
    cout << d[u][v] << '\n';
  }
}
/*
길이 있고 지날 수 있는 방향은 비용을 0으로 둔다.
길은 있지만 지날 수 없는 방향은 비용을 1로 둔다.

이에 대해 플로이드 알고리즘을 적용하면
u에서 v로 갈 때 거치는 길들 중에서,
지날 수 없는 방향으로 통과하는 길의 수를 최소화할 수 있다.

이는 곧 양방향으로 바꿔야 하는 길의 최소 개수가 된다.
*/