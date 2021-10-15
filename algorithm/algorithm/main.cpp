// Authored by : qls0860
// Co-authored by : -
// http://boj.kr/6ccbf88cdec94e7c9a14b1da89b63928

#include <bits/stdc++.h>

using namespace std;

pair<int, int> slove(int n, int m, int r, int c, int d) {
  if (n == 1) return { r, c };

  n /= 2;
  int area = n * n;

  if (d == 0) {
    if (1 <= m && m <= area) return slove(n, m, r, c, 1);
    if (area < m && m <= 2 * area) return slove(n, m - area, r + n, c, 0);
    if (2 * area < m && m <= 3 * area) return slove(n, m - 2 * area, r + n, c + n, 0);
    return slove(n, m - 3 * area, r + n - 1, c + 2 * n - 1, 3);
  }

  if (d == 1) {
    if (1 <= m && m <= area) return slove(n, m, r, c, 0);
    if (area < m && m <= 2 * area) return slove(n, m - area, r, c + n, 1);
    if (2 * area < m && m <= 3 * area) return slove(n, m - 2 * area, r + n, c + n, 1);
    return slove(n, m - 3 * area, r + 2 * n - 1, c + n - 1, 2);
  }

  if (d == 2) {
    if (1 <= m && m <= area) return slove(n, m, r, c, 3);
    if (area < m && m <= 2 * area) return slove(n, m - area, r - n, c, 2);
    if (2 * area < m && m <= 3 * area) return slove(n, m - 2 * area, r - n, c - n, 2);
    return slove(n, m - 3 * area, r - n + 1, c - 2 * n + 1, 1);
  }

  if (1 <= m && m <= area) return slove(n, m, r, c, 2);
  if (area < m && m <= 2 * area) return slove(n, m - area, r, c - n, 3);
  if (2 * area < m && m <= 3 * area) return slove(n, m - 2 * area, r - n, c - n, 3);
  return slove(n, m - 3 * area, r - 2 * n + 1, c - n + 1, 0);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;

  cin >> N >> M;

  pair<int, int> p = slove(N, M, 1, 1, 0);

  cout << p.second << ' ' << p.first;
  return 0;
}


/* 
  d�� ���� �����ν�, 0: ��, 1: ��, 2: ��, 3: �� �� �ǹ��Ѵ�.
  ��������� �̷��� ������ ����Ͽ� ö���ڰ� ���� ������ ����������.
  �� ��, n == 1�� �� �� ö������ ��ǥ�� ��Ȯ�� �� �� �ִ�.

  1. n == 1 �̸� ö������ ��ǥ�� �� �� �ִ�.
  2. n == k �� ��, ö������ ��ǥ�� �� �� �ִٸ� k + 1�� ���� �� �� �ִ�.
*/