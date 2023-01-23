// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2c872055c09e448fa3250bcfb91d7513
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[102][102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  int u, v;
  while(m--) {
    cin >> u >> v;
    d[u][v] = 1;
    d[v][u] = 1;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int ans, sum;
  int min = INF;
  for(int i = 1; i <= n; i++) {
    sum = 0;
    for(int j = 1; j <= n; j++)
      sum += d[i][j];
    if(sum < min) {
      min = sum;
      ans = i;
    }
  }
  cout << ans;
}
/*
플로이드-워셜 알고리즘을 활용한 풀이입니다.

간선 정보를 받아 u-v, v-u로 가는 경로의 길이가 1이라고 설정합니다.
자기 자신으로 향하는 경로의 길이는 0으로 설정합니다.
그외 모든 경로는 INF로 초기화하고 시작합니다.
플로이드-워셜 알고리즘(28-31번째 줄)을 통해
임의의 노드 i에서 j로 향하는 최단 거리를 2차원 배열 d에 계산합니다.

이후 한 노드 i에서 다른 노드 j로 향하는 모든 경로를 더한 값을 sum에 할당한 뒤
최솟값과 비교합니다. 최솟값보다 작을 경우 sum을 갱신하고, 답을 i 노드로 갱신합니다.
*/