// Authored by : seungmin1217
// Co-authored by : -
// http://boj.kr/9a726bf84a10402b850eefd2d9588f16
#include <bits/stdc++.h>

using namespace std;

int n, m, l;
int v[51];

bool solve(int x){
  // �߰��� �ʿ��� �ּ����� �ްԼ� ����
  int must_cnt = 0;
  int pre = 0;
  for (int i = 0; i <= n; i++) {
    int dist = v[i] - pre;

    if (dist >= x) {
	  // �� ���� : 7, ���� �ִ� 2 �϶� �ʿ��� �ްԼ� ������ 7/2 = 3��
      if (dist % x != 0)
        must_cnt += dist / x;
      // �� ���� : 8, ���� �ִ� 2 �϶� �ʿ��� �ްԼ� ������ 8/2 - 1 = 3��
      else
        must_cnt += (dist / x - 1);
    }
    pre = v[i];
  }
  // �ްԼ� ������ m���� ũ�ٸ�, ���� �ִ��� Ŀ������ (�ްԼ� ���� ����)
  if (must_cnt > m) 
    return true;
  // �ްԼ� ������ m���� ���ų� �۴ٸ�, ���� �ִ��� �۾����� �� (�ްԼ� ���� ���� ����)
  // �� for������ dist >= mid�� �ѹ��� �������� ���� ���(must_cnt == 0), ���� �ִ��� �۾����� ��
  else 
    return false;
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> n >> m >> l;

  for (int i = 0; i < n; i++)
    cin >> v[i];

  sort(v, v + n);
  // (������ �ްԼ� ~ ���� ��) ����� ���� l(��)�� ����
  v[n] = l;
  
  int st = 1, en = l;
  while(st < en){
    int mid = (st + en) / 2;
    if(solve(mid)) st = mid + 1;
    else en = mid;
  }
  
  cout << st;

  return 0;
}