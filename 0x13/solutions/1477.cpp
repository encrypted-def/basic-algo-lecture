// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/078eabd1ab6c4b3695b74e63a6c830b4
#include <bits/stdc++.h>

using namespace std;

int n, m, l;
int v[51];

int bi_search()
{
  int lo = 1; 
  int hi = l; 

  while (lo < hi) {
	int mid = (lo + hi) / 2;

	// �߰��� �ʿ��� �ްԼ��� ����
	int must_cnt = 0;

	int pre = 0;
	for (int i = 0; i <= n; i++) {
	  int dist = v[i] - pre;

	  if (dist >= mid) {
	    // �� ���� : 7, ���� �ִ� 2 �϶� �ʿ��� �ްԼ� ������ 7/2 = 3��
		if (dist % mid != 0)
		  must_cnt += dist / mid;
		// �� ���� : 8, ���� �ִ� 2 �϶� �ʿ��� �ްԼ� ������ 8/2 - 1 = 3��
		else
		  must_cnt += (dist / mid - 1);
	  }
	  pre = v[i];
	}
	// �ްԼ� ������ m���� ũ�ٸ�, ���� �ִ��� Ŀ������ (�ްԼ� ���� ����)
	if (must_cnt > m) 
	  lo = mid + 1;
	// �ްԼ� ������ m���� �۴ٸ�, ���� �ִ��� �۾����� �� (�ްԼ� ���� ���� ����)
	// �� for������ dist >= mid�� �ѹ��� �������� ���� ���(must_cnt == 0), ���� �ִ��� �۾����� ��
	else 
	  hi = mid;
  }
  return lo;
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

  cout << bi_search();

  return 0;
}