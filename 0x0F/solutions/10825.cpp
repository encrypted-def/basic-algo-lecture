// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/9383c0972bbe43c28706a98f9d3e84c4
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<tuple<int, int, int, string>> students;
  while (N--) {
    string name;
    int kor, eng, math;
    cin >> name >> kor >> eng >> math;
    students.push_back({-kor, eng, -math, name});
  }
  sort(students.begin(), students.end());
  for (auto& s : students)
    cout << get<3>(s) << '\n';
}