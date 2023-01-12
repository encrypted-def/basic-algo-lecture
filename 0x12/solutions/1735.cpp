// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/ed2a89937cce44aba6b1a18869dd16bc
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b%a, a);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d;
  cin >> a >> b >> c >> d; // a/b + c/d

  int l = lcm(b, d); // 분모
  a = l / b * a; // al / bl = (al / b) / l
  c = l / d * c; // cl / dl = (cl / d) / l

  int sum = a + c; // {(al / b) + (cl / d)} / l, 분자
  int g = gcd(l, sum);

  cout << sum / g << ' ' << l / g; // 기약분수의 분자 분모 형태로 만듦
}
