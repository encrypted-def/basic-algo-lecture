// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/581d0c95a5fc40aba608214528b21a75
#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;
int n;
int comb[1010][10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for (int i = 1; i <= 9; i++)
    comb[i][i] = 1;
  
  for (int i = 1; i <= n + 9; i++) {
    comb[i][0] = 1;
    for (int j = 1; j < min(i, 10); j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
  }

  cout << comb[n + 9][9];
}
/*
n 오르막 수의 개수는 0부터 9까지 10개의 수 중에서 n개를 중복하여 택하는 경우의 수와 같다.
H(10, n) = C(n + 9, n) = C(n + 9, 9)를 comb[n][r]배열을 통해 구한다. (0x12강 참고)
또한, 매번 C(i, 9)까지만 계산했다.
*/
