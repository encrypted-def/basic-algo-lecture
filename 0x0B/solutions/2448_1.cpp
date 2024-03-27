#include <bits/stdc++.h>
using namespace std;

void printStar(int n, int i, int j) {
  if (j <= 2*i)
    if (n == 3 && !(i == 1 && j == 1)) cout << '*';
    else printStar(n/2, i%(n/2), j%n);
  else cout << ' ';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << string(n-i-1, ' ');
    for (int j = 0; j <= n+i; j++)
      printStar(n, i, j);
    cout << '\n';
  }
}