// Authored by : qwee158
// Co-authored by : -
// http://boj.kr/091a628889c24cd79d04dd2abe6e8b5d
#include <bits/stdc++.h>
using namespace std;

int k, input[20], arr[10];

void func(int cnt, int cur) {
  if (cnt == 6) {
    for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = cur; i < k; i++) {
    arr[cnt] = input[i];
    func(cnt + 1, i + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    cin >> k;
    if (k == 0) break;
    for (int i = 0; i < k; i++) cin >> input[i];
    func(0, 0);
    cout << '\n';
  }
}
