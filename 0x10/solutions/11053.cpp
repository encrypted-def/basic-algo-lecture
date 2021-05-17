// Authored by : Hot6Mania
// Co-authored by : -
// http://boj.kr/f707b3e11fa74739bd8ebc47c121fd01

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010], d[1010];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  fill(d, d + n, 1);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
      if (a[j] < a[i]) d[i] = max(d[i], d[j] + 1);
  
  cout << *max_element(d, d + n);
}
