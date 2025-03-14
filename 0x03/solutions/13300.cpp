// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/da61fda65b7d4d7c96fde827da8d1834
#include <bits/stdc++.h>
using namespace std;

int N, K, ans=0;
int s[2][7]={};  // 성별/반별 학생 수를 저장하는 배열

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  // 학생 수 저장
  for (int i=0; i<N; ++i) {
    int a, b;
    cin >> a >> b;
    s[a][b]++;
  }

  // 필요한 방의 개수 계산
  for (int i=0; i<2; ++i) {
    for (int j=1; j<7; ++j) {
      // 배정에 필요한 만큼 방의 개수 추가
      ans += s[i][j] / K;
      // 학생이 남을 경우, 하나의 방이 더 필요하므로 방의 개수 추가
      if (s[i][j] % K) ++ans;
    }
  }
  cout << ans;
}
