// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/7e3f016c180b446fb38f8ae6b60291a6
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;
int f[MX + 2], mx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; string s;
  cin >> n >> s;

  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  cout << n - f[n - 1];
}
/*
실패함수는 자기 자신을 제외한 접두사와 접미사가 일치하는 최대 길이입니다.
광고판의 길이가 광고문구 보다 길면 앞부분부터 반복됩니다.
따라서 실패함수를 통해 반복되기 시작하는 접두사의 길이를 확인할 수 있습니다.

실패함수의 마지막 인덱스 값은 문자열 전체 중에
일치하는 접두사와 접미사의 최대 길이를 의미하므로,
이 길이를 전체 문자열 길이에서 뺀 n - f[n - 1]의 값이
곧 광고문구의 길이 중 가장 짧은 것의 길이가 됩니다.
*/
