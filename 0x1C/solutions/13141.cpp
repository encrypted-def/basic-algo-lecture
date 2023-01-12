// Authored by : jkl
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/4b74b30a692e436a83c695568ff606e8
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[205][205];
tuple<int, int, int> edges[20005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++)
    fill(d[i], d[i]+n+1, INF);

  for (int i = 1; i <= n; i++)
    d[i][i] = 0;

  for(int i = 0; i < m; i++) {
    int s, e, l;
    cin >> s >> e >> l;
    d[s][e] = min(d[s][e], l);
    d[e][s] = min(d[e][s], l);
    edges[i] = {s, e, l};
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
  }

  double ans = INF;
  for (int i = 1; i <= n; i++) {
    double totalTime = 0;
    for (int j = 0; j < m; j++) {
      int s, e, l;
      tie(s, e, l) = edges[j];
      totalTime = max(totalTime, (double)(l + d[i][s] + d[i][e]) / 2);
    }
    ans = min(ans, totalTime);
  }
  cout << fixed;
  cout.precision(1);
  cout << ans;
}
/*
  X 정점에서 불이 붙기 시작했을 때 A-B 간선이 타는 시간을 구하기 위해서는 아래 3가지가 필요하다.
  1. X -> A 정점으로 불이 이동하는 최단시간
  2. X -> B 정점으로 불이 이동하는 최단시간
  3. A-B 간선의 길이
  (1+2+3)/2 로 해당 간선이 불에 타는 최소시간을 구할 수 있다. (이해가 안갈 경우 X-A-B를 연결한 고무줄을 반으로 자른다고 생각해보자.) 모든 간선이 불에 타는
  시간은 가장 긴 간선이 불에 타는 시간과 동일하다.
  1과 2를 구하기 위해 플로이드-워셜을 이용한다.
  어떤 정점에서 시작했을 때 가장 빠르게 그래프가 불에 타는지 알 수 없기 때문에 모든 정점을 확인한다.
*/
