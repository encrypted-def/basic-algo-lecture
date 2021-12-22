// Authored by : unluckyjung
// Co-authored by : -
// https://www.acmicpc.net/source/share/d2361474c79c496b81d06711d7e7ba5c
#include <bits/stdc++.h>

using namespace std;

int humanCount, cookieCount;
int cookies[1000002];
int maxCookieSize;
int answer;

bool isCanDivide(int cookieSize) {
  if (cookieSize == 0) return false;
  int dividedCookieCount = 0;
  for (int i = 0; i < cookieCount; ++i) {
    dividedCookieCount += cookies[i] / cookieSize;
  }
  return dividedCookieCount >= humanCount;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> humanCount >> cookieCount;
  for (int i = 0; i < cookieCount; ++i) {
    cin >> cookies[i];
    maxCookieSize = max(maxCookieSize, cookies[i]);
  }

  int st = 0;
  int ed = maxCookieSize;
  int mid;

  while (st <= ed) {
    mid = st + (ed - st) / 2;
    if (isCanDivide(mid)) {
      answer = mid;
      st = mid + 1;
    } else {
      ed = mid - 1;
    }
  }

  cout << answer << "\n";
  return 0;
}
