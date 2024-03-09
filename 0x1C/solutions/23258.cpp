// Authored by : JM911
// Co-authored by : -
// http://boj.kr/c7820ba2110643c0b84124b50b732e94
#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 302
int N, Q;
int D[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;

  for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++){
      cin >> D[0][i][j];
      if(D[0][i][j]==0 && i!=j)  // i!=j 인데 0을 입력 받은 경우 문제에서 준 최대 크기보다 큰 값으로 대입
      D[0][i][j] = 180000;
    }

  // 3차원 배열 D의 첫 인덱스는 1, 2, ..., i번 도시까지 거쳐 갈 수 있을 때의 최소 거리값을 뜻함
  // 즉, D[i][s][e] 는 중간 도시의 번호가 i 이하임을 보장하면서 s 부터 e 까지 도달하는 거리의 최솟값이다.
  for(int i=1; i<=N; i++)
    for(int s=1; s<=N; s++)
      for(int e=1; e<=N; e++)
        D[i][s][e] = min(D[i-1][s][e], D[i-1][s][i] + D[i-1][i][e]);

  while(Q--){
    int C, s, e;
    cin >> C >> s >> e;

    int ans = D[C-1][s][e];
    if(ans > 175000)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
}
/*
  핵심 아이디어는 1 + 2 + 4 + ... + 2^(C-1) = 2^C - 1 을 이용하는 것
  즉, 아무리 돌아다녀도 C 이상의 도시에 방문하지만 않으면 총 이슬의 양은 2^C 이상이 될 수 없다.
  위 식에 의해 C-1 이하의 도시는 어디든 자유롭게 다닐 수 있다.
  D를 삼차원 배열로 선언하여 각 층에 1, 2, 3, ..., i번 도시까지 방문할 수 있는 경우의 플로이드 알고리즘 결괏값을 저장한다.
  이후 문제에서 원하는 값을 받아 출력만 하면 된다.
*/
