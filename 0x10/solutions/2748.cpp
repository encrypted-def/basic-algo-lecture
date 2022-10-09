// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/fca58deb2214447782fe6483572acdb8
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[100];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1, d[2] = 1;
  for (int i = 3; i <= n; i++)
    d[i] = d[i - 1] + d[i - 2];
  cout << d[n];
}