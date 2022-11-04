// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/7b4898813082467bb053d38e54a1f83f
#include <bits/stdc++.h>
using namespace std;

int n, w, L;
int a[1000]; // i번째 트럭의 무게
int cross[1000]; // cross[i] : i번째 트럭이 다리에 올라간 시간
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> w >> L;
  for (int i = 0; i < n; i++) cin >> a[i];
  cross[0] = 1;
  int sum = a[0];
  int idx = 0; // 현재 다리에 올라가있는 트럭 중 가장 앞에 있는 트럭의 번호
  for (int i = 1; i < n; i++) {
    while (i - idx + 1 > w || sum + a[i] > L) sum -= a[idx++];
    sum += a[i];
    if (idx == 0)
      cross[i] = cross[i - 1] + 1;
    else
      cross[i] = max(cross[i - 1] + 1, cross[idx - 1] + w);
  }
  cout << cross[n - 1] + w;
}
