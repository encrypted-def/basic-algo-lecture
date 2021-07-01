// Authored by : cpprhtn
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/1e1d8717951a425c94049401b38053b6
#include <bits/stdc++.h>
using namespace std;

void print_star(int i, int j, int num) {
  if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
    cout << ' ';
  else {
    if (num / 3 == 0)
      cout << '*';
    else
      print_star(i, j, num / 3);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num;
  cin >> num;
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) print_star(i, j, num);
    cout << '\n';
  }
}
