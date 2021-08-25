// Authored by : OceanShape700
// Co-authored by : -
// http://boj.kr/c3e2c2e9d8454670be90fbe3781967b9
#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[9];
bool vis[9];

// cnt: 현재 선택한 개수
// start: 선택 가능한 시작 수
void bt(int cnt, int start){
  if(cnt == M){
    for(int i = 0; i < N; ++i)
      if(vis[i]) cout << num[i] << ' '; // 방문한 수 출력
    cout << '\n';
    return;
  }
  // start부터 N까지 확인
  for(int i = start; i < N; ++i){
    if(vis[i]) continue;
    vis[i] = true;
    // 방문 여부를 확인하므로, i부터 시작
    // start+1기 아닌 이유: i == N일 때, M개보다 적게 선택한 경우도 있기 때문
    bt(cnt+1, i);
    vis[i] = false;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i < N; ++i) cin >> num[i];
  sort(num, num + N); // 수열을 오름차순으로 정렬
  bt(0, 0);
}
