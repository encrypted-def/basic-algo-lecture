// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/1d051b9816e244069a1a73879cc0ef92
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> arr(N);
  while (N--) cin >> arr[N];
  sort(arr.begin(), arr.end());
  for (int v : arr) cout << v << "\n";
}