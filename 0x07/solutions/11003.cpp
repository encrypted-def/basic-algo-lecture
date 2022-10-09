// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a3aef39bd578432d814a0be26957bc9c
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  deque<pair<int, int>> dq;

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;

    // 새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치하도록 합니다.
    // deque안의의 숫자들은 오름차순 상태를 유지하게 되고, 구간내 가장 작은값은 항상 맨앞(front)에 있는 상태를 가지게 됩니다.
    while (!dq.empty() && dq.back().second >= num) {
      dq.pop_back();
    }
    
    // 새로운 숫자는 항상 삽입됩니다.
    dq.push_back({i, num});

    // 주어진 구간을 벗어나는 outdate된 숫자들은 제거해줍니다.
    if (dq.front().first <= i - m) {
      dq.pop_front();
    }

    cout << dq.front().second << " ";
  }

  return 0;
}
