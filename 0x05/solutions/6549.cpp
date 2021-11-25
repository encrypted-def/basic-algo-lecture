// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/d98aedfde0e444509de83f1a21c8ef7e
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    stack<pair<int, int>> S;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int h;
      cin >> h;
      int idx = i;
      while (!S.empty() && S.top().X >= h) {
        ans = max(ans, 1LL * (i - S.top().Y) * S.top().X);
        idx = S.top().Y;
        S.pop();
      }
      S.push({h, idx});
    }
    while (!S.empty()) {
      ans = max(ans, 1LL * (n - S.top().Y) * S.top().X);
      S.pop();
    }
    cout << ans << '\n';
  }
}

/*
스택에는 (높이, 해당 높이가 최초로 등장한 위치)가 저장된다. 기본적으로 스택은
높이에 대한 monotone stack으로 관리된다. 스택에서 pop이 발생할 때 마다 현재
스택의 top을 가지고 만들 수 있는 직사각형의 넓이를 계산할 수 있다.
long long으로의 형변환을 편하게 처리하기 위해 1LL을 매번 곱했고, 그냥 스택
자체를 pair<long long, long long>으로 선언해도 크게 상관 없다.
*/
