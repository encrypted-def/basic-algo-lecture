// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/9037215a857644b2b44dfda536044e81
#include <bits/stdc++.h>
using namespace std;

int dist[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 100;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      dist[i][j] = 10000;
      if(i == n || j == n ) dist[i][j] = 4999;
      if(i == j) dist[i][j] = 0;
    }

  cout << n << '\n';
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      cout << dist[i][j] << ' ';
      if(j == n) cout << '\n';
    }
}
/*
지구이의 틀린 코드로 얻은 인접 행렬을 D,
지구이의 올바른 코드로 얻은 인접 행렬을 E라고 하자.

D와 E의 성분이 9700개 이상 다른 데이터를 출력해야 한다.

지구이의 첫번째 코드는 N번 정점을 경유하는 경로를 고려하지 않는다.
즉, i -> N, N -> j 경로가 최단 경로로 고려되지 않는다.
따라서, dist[i][j] > dist[i][N] + dist[N][j]를 만족하는 데이터를 만들어야 한다.

위 코드에선 dist[i][j]가 10000이기 때문에
dist[i][N] = dist[N][j] = 4999로 둬서 이를 만족하게 하였다.

대각 성분은 모두 0이 되어야 하므로, D와 E의 성분이 동일하다.
또한, 여기서 N행 및 N열 성분들은 N번 정점을 경유하든 하지 않든 상관 없기 때문에,
9700개 이상의 데이터가 잘못되기 위해선 N은 100이어야 한다.
실제로 위 코드를 제출하면 cnt는 9702가 된다.
*/