// Authored by : OceanShape700
// Co-authored by : -
// http://boj.kr/6416403c1a894806a5564824fd1322d1
#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[8];

void bt(int K){
  // M개를 선택했을 경우
  if(K == M){
    for(int i = 0; i < M; ++i)
      cout << num[i] << ' '; // 선택한 수 출력
    cout << '\n';
    return;
  }
  for(int i = 1; i <= N; ++i){
    num[K] = i; // 선택한 수 저장
    bt(K + 1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  bt(0);
}
