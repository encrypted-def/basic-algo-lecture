// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/5af73c100b294e40b6bcc4463ab1c879
#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
int cnt[100005];  // cnt[i]: i번째 수의 등장 횟수
int a[200005];    // 수열 a_i를 저장하는 배열

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> a[i];

  // 연속 부분 수열의 시작을 st, 끝을 en으로 정의
  int en = 0;
  // 처음 위치 a_0의 등장 횟수 추가
  ++cnt[a[en]];
  for (int st = 0; st < N; ++st) {
    // en + 1이 수열 a_i의 끝(N-1)을 넘지 않거나,
    // a_(en + 1)의 등장횟수를 높여도 K를 넘지 않을 경우,
    // en을 올려 수열의 길이 연장
    while(en + 1 != N && cnt[a[en + 1]] < K) {
      ++en;
      cnt[a[en]]++; // 새로운 수열 끝부분을 확인 후, 횟수 추가
    }
    // 연장이 끝날 경우, 현재 길이를 최장 길이와 비교
    ans = max(ans, en - st + 1);
    // 시작 인덱스 값을 올리기 전,
    // 수열의 시작에 해당하는 수의 등장횟수를 줄인다
    cnt[a[st]]--;
  }
  cout << ans;
}
