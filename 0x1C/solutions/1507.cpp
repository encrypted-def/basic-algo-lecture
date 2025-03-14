// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/f1828145b7b94868bc867021a458820a
#include <bits/stdc++.h>
using namespace std;

int n;
int d[22][22];
bool u[22][22];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) cin >> d[i][j];
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      bool isunit = true;
      for(int k = 1; k <= n; k++) {
        if(k == i || k == j) continue;
        int tmp = d[i][k] + d[k][j];
        if(tmp < d[i][j]) {cout << -1; return 0;}
        else if(tmp == d[i][j]) isunit = false;
      }
      if(isunit) u[i][j] = u[j][i] = 1;
    }

  int ans = 0;
  for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
      if(u[i][j]) ans += d[i][j];

  cout << ans;
}
/*
u와 v를 제외한 다른 정점을 k라고 두고,
u에서 k를 거쳐 v로 가는 거리 d[u][k] + d[k][v]로 계산하며,
이를 dukv라고 하자.

문제에 입력으로 주어지는 배열은 도시 간 최소거리이기 때문에
dukv는 d[u][v]보다 작아선 안 된다.
이 값이 d[u][v]보다 작은 경우 -1를 출력하고 프로그램을 종료한다.

만약 d[u][v]가 dukv와 같은 경우, d[u][v]는 d[u][k]와 d[k][v]로 구성된 길이며,
직접 u와 v를 연결하는 유일한 도로가 아니다.
*/