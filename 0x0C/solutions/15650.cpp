// Authored by : OceanShape700
// Co-authored by : -
// http://boj.kr/0e1e3105a42c457099594271ab64836c
#include <bits/stdc++.h>
using namespace std;

bool vis[9];
int N, M;

// cnt: 현재 선택한 개수
// start: 선택 가능한 시작 수(오름차순으로 정렬된 수열이기 때문에 가능)
void bt(int cnt, int start){
  // M개를 선택했을 경우
  if(cnt == M){
    for(int i = 1; i <= N; ++i)
      if(vis[i]) cout << i << ' '; // 방문한 수를 출력
    cout << '\n';
  }
  // start부터 N까지 확인
  // start+1이 아닌 이유: i == N일 때, M개보다 적게 선택한 경우도 있기 때문
  for(int i = start; i <= N; ++i){
    if(vis[i]) continue;
    vis[i] = true;
    bt(cnt + 1, i); // 선택한 수부터 다시 확인
    vis[i] = false;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  bt(0, 1);
}
