// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/425091930ba240849b4dba7799b5e357
#include <bits/stdc++.h>
using namespace std;

int dist[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = 100;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      dist[i][j] = 10000;
      if(i == n - 1 || j == n - 1 || i == j) dist[i][j] = 0;
    }

  cout << n << '\n';
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cout << dist[i][j] << " \n"[j + 1 == n];
}
/*
지구이의 코드로 AC가 뜨는 데이터를 출력하는 것이 목표다.
즉, 인접 행렬 성분이 9700개 이상 잘못된 데이터를 출력해야 한다.

지구이의 첫번째 코드는 N번 정점을 경유하는 경로를 고려하지 않는다.
즉, i -> N, N -> j 경로가 최단 경로로 고려되지 않는다.
따라서, 인접행렬 D의 N번째 행과 열에 다른 비용들보다 적절히 작은 값을 대입하면 된다.
위 코드에선 0을 대입한다.

특별히 9700개 이상의 비용이 달라야 하고, 그중에서 대각 성분은 모두 0이 되어야 한다.
여기서 k행과 k열 비용들은 k를 경유하든 하지 않든 영향이 없기 때문에
9700개 이상의 데이터가 잘못되기 위해선 N은 100이어야 한다.
*/