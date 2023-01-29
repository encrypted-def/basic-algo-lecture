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
지구이의 틀린 코드로 얻은 인접행렬을 D,
지구이의 올바른 코드로 얻은 인접행렬을 E라고 하자.

D와 E의 성분이 9700개 이상 다른 데이터를 출력해야 한다.
여기서 출력할 데이터는 dist 배열에 저장한다.

지구이의 첫번째 코드는 N번 정점을 경유하는 경로를 고려하지 않는다.
즉, i -> N, N -> j 경로가 최단 경로로 고려되지 않는다.
따라서, dist[i][j] > dist[i][N] + dist[N][j]인 경우에 D와 E의 성분이 달라진다.

위 코드에서는 dist[i][j]를 10000으로 두고
dist[i][N] = dist[N][j] = 4999으로 설정해 위 조건을 만족시켰다.

D와 E의 대각 성분은 모두 0으로 동일하다.
또한, N행 및 N열 성분들은 N번 정점을 경유하든 하지 않든 상관없다.
따라서 9700개 이상의 데이터가 잘못되기 위해선 N은 100이어야 한다.
실제로 위 데이터를 통해 서로 다른 D와 E의 성분을 세면 총 9702개다.
*/