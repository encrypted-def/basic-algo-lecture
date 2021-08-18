// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/2aa686e6604e4e1286fa7d91ae74531a
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  while (N--) {
    int a[26] = {}; // 각 문자의 개수를 저장하는 배열
    string s1, s2;
    cin >> s1 >> s2;

    for (auto c : s1) a[c-'a']++; // 첫 번째 문자열의 각 문자는 개수+1
    for (auto c : s2) a[c-'a']--; // 두 번째 문자열의 각 문자는 개수-1

    // 0이 아닌 배열의 요소가 있을 경우, 개수가 다른 문자가 존재하므로 false
    bool isPossible = true;
    for (int i : a) if (i != 0) {isPossible = false;};

    isPossible ? cout << "Possible" : cout << "Impossible" ;
    cout << '\n';
  }
}
