// Authored by : syoh0708
// Co-authored by : -
// http://boj.kr/3589e6590845469191b7873b71550403
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1'000'000'000;
int n, ans = MAX;
int a[605];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a, a + n);

  for (int i1 = 0; i1 < n; i1++) {
    for (int i2 = i1 + 3; i2 < n; i2++) {
      int j1 = i1 + 1, j2 = i2 - 1;

      while (j1 < j2) {
        ans = min(ans, abs(a[i1] + a[i2] - a[j1] - a[j2]));

        if (a[i1] + a[i2] <= a[j1] + a[j2]) j2--;
        else j1++;
      }
    }
  }

  cout << ans;
}
/*
답을 구성하는 눈사람이 a,b,c,d(a <= b <= c <= d)라고 할 때 (a, d)가 한 묶음이고
(b, c)가 한 묶음인건 자명하기 때문에 인덱스를 i1 < j1 < j2 < i2로 둘 수 있다.
a[i1]+a[i2]와 a[j1]+a[j2]가 근접한 (j1, j2) 쌍을 구하면 된다.
*/
