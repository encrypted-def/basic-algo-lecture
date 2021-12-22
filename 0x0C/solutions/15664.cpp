// Authored by : connieya
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/7c17e31c609d4010ad339cec1f7ed280
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int k, int st) {
  if (k == m) {
    for (int i = 0; i < m; ++i)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  int tmp = 0;
  for (int i = st; i < n; ++i) {
    if (tmp != num[i]) { // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
      arr[k] = num[i];
      tmp = arr[k];
      func(k + 1, i + 1);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num, num + n);
  func(0, 0);
}
