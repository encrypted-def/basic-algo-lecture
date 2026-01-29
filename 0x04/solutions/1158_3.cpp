// Authored by : rudevico
// Co-authored by :
// http://boj.kr/516df9bce2eb4a74acbb42181fd9ba30
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  list<int> L;
  for (int i = 1; i <= n; i++) L.push_back(i);
  auto it = L.begin();

  cout << "<";
  while (!L.empty()) {
    int move = k - 1;

    // 원을 돌면서 제거할 사람까지 이동 (실제로는 직선이지만 마치 원처럼 작동하도록 보정)
    while (move--) {
      // 주의: LinkedList는 항상 처음 또는 끝인지 확인하고 보정해주는 작업이 필요하다.
      if (next(it) == L.end()) it = L.begin();
      else ++it;
    }

    // 출력 및 제거
    cout << *it;
    it = L.erase(it);
    if (!L.empty()) cout << ", ";

    // 주의: LinkedList는 항상 처음 또는 끝인지 확인하고 보정해주는 작업이 필요하다.
    if (it == L.end()) it = L.begin();
  }
  cout << ">";
}

/*
STL list를 이용한 풀이.
원형 연결 리스트가 아니기 때문에, 마치 원형처럼 돌려면 끝 위치인지 판단하고 처음으로 이동시켜야 하는 불편함이 있음.
*/
