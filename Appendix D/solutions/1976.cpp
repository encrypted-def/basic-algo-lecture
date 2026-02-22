// Authored by : erick12(BOJ)/erickk1212(Github)
// Co-authored by : -
// http://boj.kr/f346c8a343b041edb4253c6382325270
#include <bits/stdc++.h>
using namespace std;
int parent[210];
bool road[210][210];
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
int plan[210];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  unionfindsetup(n);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> road[i][j];
      if (road[i][j]) dounion(i, j);
    }
  }
  for (int i = 0; i < m; i++)
  {
    cin >> plan[i];
    if (i)
    {
      if (find(plan[i - 1]) != find(plan[i]))
      {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
