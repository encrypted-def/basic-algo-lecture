// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/d77ea5b806134b5898973f87ece76dae
#include <bits/stdc++.h>
using namespace std;

long long n,p,q;
unordered_map<long long,long long> table;

long long f(long long i) {
  if(table.find(i) != table.end())
    return table[i];

  if (i == 0) {
    table[i] = 1;
    return table[i];
  }

  table[i] = f(i/p) + f(i/q);
  return table[i];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> p >> q;
  cout << f(n);
}
