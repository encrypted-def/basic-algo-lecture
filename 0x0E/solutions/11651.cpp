// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/14e7ff380ec945d086845dfa9dbba5f2
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int,int> p[100004];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i].Y >> p[i].X;
  sort(p, p + n);
  for (int i = 0; i < n; i++)
    cout << p[i].Y << ' ' << p[i].X << '\n';
}

/*
pair의 정렬 순서는 first를 먼저 비교하기 때문에 둘의 자리를 바꿔서 집어넣은 후 정렬함.
*/
