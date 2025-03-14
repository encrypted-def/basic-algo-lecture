// Authored by : HDLay
// Co-authored by : -
// http://boj.kr/189891e34a774527af857b715027b275
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int comb[202][202];
vector<char> ans;

int main(void) {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;

  for (int i = 1; i <= 200; i++) {
    comb[i][0] = 1;
    comb[i][i] = 1;
    for (int j = 1; j < i; j++) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
      if (comb[i][j] > 1'000'000'000) comb[i][j] = 1'000'000'001; // 값이 1'000'000'000을 초과할 경우, 이후 연산에서의 overflow를 막기 위해 1'000'000'001로 설정
    }
  }

  while (n && m) {
    if (k > comb[n + m - 1][m]) {
      k -= comb[n + m - 1][m];
      ans.push_back('z');
      m--;
    }
    else {
      ans.push_back('a');
      n--;
    }
  }

  while (n--) ans.push_back('a');
  while (m--) ans.push_back('z');

  if (k > 1) cout << -1;
  else for (auto c : ans) cout << c;
}

/*
n, m, k값을 감소시키며 가장 큰 자리수부터 문자를 확정해나간다.
현재 사용할 수 있는 'a'와 'z'의 개수가 각각 n, m개일 때, (n + m)번째 자리수의 문자가 'a'일 경우의 수는 (n + m - 1)C(m) 가지이다.
따라서 현재 k값이 이보다 클 경우 (n + m)번째 문자는 'z'로 확정할 수 있다.
*/