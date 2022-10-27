// Authored by : ZeroOnePro
// Co-authored by : -
// http://boj.kr/2ea93e817370412287681348cde0c06a
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n), lis;
  for (auto& pt : s) cin >> pt;
  lis.push_back(0);  // 편의상 추가
  for (int e : s) {
    if (lis.back() < e)
      lis.push_back(e);
    else {
      int lb = lower_bound(lis.begin(), lis.end(), e) - lis.begin();
      lis[lb] = e;
    }
  }
  cout << lis.size() - 1;
  return 0;
}

/**
 * lis배열이 비었거나 현재 원소보다 큰 값이 없다면 lis에 현재 원소를 추가한다
 * lis배열 내에 현재 원소보다 큰 값이 한 개이상 있을 때, 이것보다 크면서 제일 작은 값을 찾아 현재원소와 대치한다
 * 간단한 예시를 하나 살펴보자
 * {10, 20, 30, 15, 20, 30, 50, 40, 45, 60}
 * lis의 초기값은 빈 배열이다
 * 10을 살펴본다, 배열이 비었으니 추가 / {10}
 * 20을 살펴본다, 20보다 큰 값이 없으니 추가 / {10, 20}
 * 30을 살펴본다, 30보다 큰 값이 없으니 추가 / / {10, 20, 30}
 * 15를 살펴본다, 15보다 큰 값은 20과 30이 있는데 그 중 가장 작은 값인 20이 15로 대치된다 / {10, 15, 30}
 * 이 과정을 마지막 원소까지 반복한다
 * 15가 추가되는 과정을 보면 올바르지 않은 lis임을 알 수 있는데, 길이를 구하는 문제 한정해서는 상관없다
 * 원소를 제거하는 것이 아닌 대치로 이뤄지기 때문에 길이가 유지되기 때문이다
 */