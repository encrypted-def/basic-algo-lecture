// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/f68f0ddb03c6401aab2ea0795a056ca5
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;
int f[MX + 2], mx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; string s;
  cin >> n >> s;

  for(int i = 1; i < n; i++) {
    int j = f[i - 1];
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  cout << n - f[n - 1];
}
/*
실패함수는 자기 자신을 제외한 접두사와 접미사가 일치하는 최대 길이입니다.
광고는 본래 광고 길이보다 긴 경우, 앞부분부터 다시 반복되어 보여주기 떄문에
반복되는 부분이 곧 접미사가 됩니다.
따라서, 실패함수의 마지막 인덱스 값은 
*/