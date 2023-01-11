// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/8e359fb229604e5f848bf6c9e72afea8
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (a ? gcd(b % a, a) : b); }

int lcm(int a, int b) { return (a / gcd(a, b) * b); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d;
  cin >> a >> b >> c >> d; // a/b + c/d

  int l = lcm(b, d);
  a = l / b * a; // al / bl = (al / b) / l
  c = l / d * c; // cl / dl = (cl / d) / l

  int sum = a + c; // {(al / b) + (cl / d)} / l
  int g = gcd(l, sum);

  cout << sum / g << ' ' << l / g; // 기약분수의 분자 분모 형태로 만듦
}