// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/039530fbae654100939d10d8a7c10bd7
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<tuple<int, int, string>> members;
  for (int i = 0; i < N; i++) {
    int age;
    string name;
    cin >> age >> name;
    members.push_back({age, i, name});
  }
  sort(members.begin(), members.end());
  for (auto [age, _, name] : members)
    cout << age << " " << name << '\n';
}