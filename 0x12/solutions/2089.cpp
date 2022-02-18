// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/6e72b8d78bdf4935a713f079a03dc8ef
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  while (n) {
    if (n < 0) {
      if (-n % 2 == 0) {
        n = -n / 2;
        v.push_back(0);
      }
      else {
        n = -n / 2 + 1;
        v.push_back(1);
      }
    }
    else {
      v.push_back(n % 2);
      n = -(n / 2);
    }
  }
  reverse(v.begin(), v.end());
  for (int i : v) cout << i;
}
/*
1. n이 음수인 경우
1-1. -n이 2로 나누어 떨어질 경우 -n / 2를 몫으로 0을 나머지로 갖는다.
1-2. -n이 2로 나누어 떨어지지 않을 경우 -n / 2를 몫으로 가지면 나머지가 -1이 되기 때문에 -n / 2에 1을 더한 값을 몫으로 가지고 나머지를 1로 만들어 준다.
2. n이 양수인 경우 음수의 곱으로 양수를 만들 수 있으므로 2로 나눈 몫과 나머지를 구하고 몫을 음수로 바꿔 준다.

예시
1-1. -16 = -2 * 8 + 0
1-2. -15 = -2 * 7 - 1 (X) -> -2 * 8 + 1 (O)
2. 15 = -2 * -7 + 1, 16 = -2 * -8 + 0
*/
