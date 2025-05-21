// Authored by : erick12(BOJ)/Erickk1212(Github)
// Co-authored by : -
// http://boj.kr/53c3baf12cb8446699fe398d0b171654
#include<bits/stdc++.h>
using namespace std;
int parent[100000];
int find(int x)
{
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}
void dounion(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x != y) parent[x] = y;
}
void unionfindsetup(int x)
{
  for (int i = 0; i <= x; i++)
  {
    parent[i] = i;
  }
}
int n, m;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
  }
  int t = 0;
  int ans = m;
  for (int i = 0; i < m; i++)
  {
    int num;
    cin >> num;
    t = find(num);
    if (t == 0)
    {
      ans = i;
      break;
    }
    parent[t] = t - 1;
  }
  cout << ans;
  return 0;
}
