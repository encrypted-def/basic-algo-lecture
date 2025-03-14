// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/c17a84c98cdc40b1a3a72b249decca79
#include <bits/stdc++.h>
using namespace std;

int n, layer;
int main(void) {
  cin >> n;
  n--;
  while (0 < (n -= 6*layer)) layer += 1;
  cout << ++layer;
}