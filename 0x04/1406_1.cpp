// http://boj.kr/3c736db6075546b693cad9a55ccfc68e
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string init;
  cin >> init;
  list<char> L;
  for (auto c : init) L.push_back(c);
  auto cursor = L.end();
  int q;
  cin >> q;
  while (q--) {
    string op;
    cin >> op;
    if (op[0] == 'P') {
      string add;
      cin >> add;
      L.insert(cursor, add[0]);
    }
    else if (op[0] == 'L') {
      if (cursor != L.begin()) cursor--;
    }
    else if (op[0] == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else { // 'B'
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto c : L) cout << c;
}
