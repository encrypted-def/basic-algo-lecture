// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/7a7deeedae3b4177a1ed53482685bf15
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2'000'000, HALF = MXN / 2;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<bool> isnum(MXN + 2);
  int N, t;
  cin >> N;
  while (N--) {
    cin >> t;
    isnum[t + HALF] = true;
  }
  for (int i = MXN; i >= 0; i--)
    if (isnum[i]) cout << i - HALF << '\n';
}

/*
수의 등장 여부만 확인, 인덱스를 0에서부터 시작할 수 있게 1,000,000을 더함.
*/
