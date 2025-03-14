// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/5a28bc020b454d739944f494674a61a8
#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[102][10002];

void compress(int a[]) {
  vector<int> v(a, a + n);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
}

bool compare(int a[], int b[]) {
  for (int k = 0; k < n; k++)
    if (a[k] != b[k]) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> arr[i][j];
    compress(arr[i]);
  }

  int ans = 0;
  for (int i = 0; i < m - 1; i++)
    for (int j = i + 1; j < m; j++)
      ans += compare(arr[i], arr[j]);
  cout << ans;
}
/*
두 우주를 좌표 압축하였을 때 동일하면 균등한 우주이다.
*/
