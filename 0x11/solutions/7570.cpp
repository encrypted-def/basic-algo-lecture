// Authored by : unluckyjung
// Co-authored by : -
// http://boj.kr/d3653e0ab40644c29b02d67ec754f8d1
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 2;

int dp[MAX];
int studentCount, studentNumber;
int chainMaxLIS;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> studentCount;

  for (int i = 0; i < studentCount; ++i) {
    cin >> studentNumber;
    dp[studentNumber] = dp[studentNumber - 1] + 1;
    chainMaxLIS = max(chainMaxLIS, dp[studentNumber]);
  }

  cout << studentCount - chainMaxLIS << "\n";

  return 0;
}

/*
(N - 최대로 번호가 연속해서 증가하게끔 배치되어있는 어린이들의 수)가 정답이다.
최대로 번호가 연속해서 증가하게끔 배치되어있는 어린이들의 수때 이 코드에서 제시한
방법 이외에도 각 어린이들의 위치를 배열에 담아둔 후 처리를 하는 방법도 있다.
*/
