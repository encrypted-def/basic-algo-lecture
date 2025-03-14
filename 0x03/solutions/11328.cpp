// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a3d03c0124b544759d306668e55bbf4b
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
    // 중괄호가 없어도 문제는 없으나 가독성을 위해 삽입
    for (int i : a){
      if (i != 0) isPossible = false;
    }

    if(isPossible) cout << "Possible\n";
    else cout << "Impossible\n";
  }
}
