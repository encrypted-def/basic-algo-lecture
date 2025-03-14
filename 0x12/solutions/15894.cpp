// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/ebecc4bfc76c4a4dace118b27d949c7e
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  cout << 4ll * n;
}
/*
윗면에 해당하는 변을 위로 붙이고, 옆면을 각 옆면으로 붙이면
하나의 정사각형의 둘레로 생각할 수 있습니다.
또한, n의 최대값으로는 1e9까지 들어갈 수 있으므로 
long long으로 캐스팅하여 출력합니다.
*/