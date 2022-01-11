// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/5a5a95bcc0644b138ad6850e5db9e87a
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, a, b;
pair<int, int> p[100004];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> p[i].X >> p[i].Y;
  }
  sort(p, p + n);
  for(int i = 0; i < n; i++) cout << p[i].X << ' ' << p[i].Y << '\n';
}
