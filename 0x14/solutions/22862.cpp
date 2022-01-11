// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/99ae176e3df145bb860d092f53e4c2c4
#include <bits/stdc++.h>
using namespace std;

int N, K, st, en, cnt, ans;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  vector<int> arr(N);
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  for (; en < N; en++) {
    cnt += arr[en] % 2;
    /* 
    지금 삭제한 홀수들이 K보다 많으면
    st를 앞으로 옮기며 삭제합니다.
    */
    while (K < cnt)
      cnt -= arr[st++] % 2;
    ans = max(ans, en - st - cnt + 1);
  }
  cout << ans;
}