// Authored by : OceanShape700
// Co-authored by : -
// http://boj.kr/91ac884c4b864dc99f1a8342ef67845b
#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[9];

// cnt: 현재 선택한 개수
// start: 선택 가능한 시작 수
void bt(int cnt, int start){
  // M개를 선택했을 경우
  if(cnt == M){
    for(int i = 0; i < M; ++i)
      cout << num[i] << ' '; // 선택한 수 출력
    cout << '\n';
    return;
  }
  // start부터 N까지 확인
  for(int i = start; i <= N; ++i){
    num[cnt] = i; // 선택한 수 저장
    bt(cnt + 1, i);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  bt(0, 1);
}
