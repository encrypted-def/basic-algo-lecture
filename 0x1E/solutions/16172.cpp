// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/d9ea37b3af8d44648f962fbbef11c440
#include <bits/stdc++.h>
using namespace std;

vector<int> f_fun;

vector<int> failure(string& s){
  vector<int> f(s.size());
  for(int i = 1; i < (int)s.size(); i++){
    int j = f[i-1];
    while(j > 0 && s[i] != s[j]) j = f[j-1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}

bool solve(string&s, string&k){
  int j = 0;
  for(int i = 0; i < (int)s.size(); i++){
    if(s[i] >= '0' && s[i] <= '9') continue;
    while(j > 0 && s[i] != k[j]) j = f_fun[j-1];
    if(s[i] == k[j]) j++;
    if(j == (int)k.size()) return 1;
  }
  return 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s, k;
  cin >> s >> k;
  f_fun = failure(k);
  cout << solve(s, k);
}
/*
문자열 s 안에서 키워드 k를 찾을 때
중간에 숫자인 문자가 들어가는 경우
다음 인덱스로 넘어가도록 함(22번째 줄)
*/