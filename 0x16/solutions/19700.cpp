// Authored by : syoh0708
// Co-authored by : -
// http://boj.kr/c805ab6be00244ba9b563dbec6619ca5
#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[500005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second;

  sort(a, a + n, greater<pair<int, int>>());

  multiset<int> s;

  for (int i = 0; i < n; i++) {
    auto it = s.lower_bound(-a[i].second + 1);
    if (it == s.end()) s.insert(-1);
    else {
      int val = *it;

      s.erase(it);
      s.insert(val - 1);
    }
  }

  cout << s.size();
}
/**
 * 키의 내림차순으로 정렬한 뒤 수강생을 팀에 배정하면 
 * 수강생 S를 인원이 n명인 팀에 배정하면 S의 등수는 (n + 1)등이 된다.
 * 따라서 수강생 S가 x등 안에 들고 싶다면, 
 * 팀원이 (x - 1)명 이하인 팀이 있다면 그 중 팀원이 가장 많은 팀에 배정하고
 * 팀원이 (x - 1)명 이하인 팀이 없다면 새로운 팀을 배정한다.
 * multiset이 기본적으로 오름차순으로 정렬되고, (x - 1)명 이하인 팀 중에서 팀원 수가 가장 많은 팀을 원하기 때문에
 * 팀원 수에 -(마이너스)를 붙이고, lower_bound로 찾으면 된다.
 */
