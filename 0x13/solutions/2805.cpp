// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/0d301f4f0b4e4beebc7889e220b0145f
#include <bits/stdc++.h>
using namespace std;

int tree[1000002];
int n, m;

// x만큼 잘라냈을 때 남는 나무의 길이가 m 이상인가?
bool solve(int x) {
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    if (tree[i] <= x) continue;
    cur += (tree[i] - x);
  }
  return cur >= m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> tree[i];

  int st = 0;
  int en = *max_element(tree, tree+n);

  while (st < en) {
    int mid = (st+en+1)/2;
    if (solve(mid))
      st = mid;
    else 
      en = mid - 1;
  }
  cout << st;
}
