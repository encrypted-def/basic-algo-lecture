// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/6ded5e77cbdf46cea5e1a97c3b08e305
#include <bits/stdc++.h>
using namespace std;

int tmp, ans;
int sign = 1;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> input;
  for (char c: input){
    if (c == '+' || c == '-'){
      ans += tmp * sign;
      if (c == '-') sign = -1;
      tmp = 0;
    }
    else{
      tmp *= 10;
      tmp += c - '0';
    }
  }
  ans += tmp * sign;
  cout << ans;
}