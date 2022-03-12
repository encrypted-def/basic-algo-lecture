// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : diyamea
// http://boj.kr/22b96fcb29164a9a837a72d5010d1188
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k,l;
  cin >> k >> l;
  unordered_map<string, int> signup{};
  for(int i=0; i<l; ++i) {
    string student_num;
    cin >> student_num;
    if(signup.find(student_num) != signup.end()) {
      signup.erase(student_num);
      signup[student_num] = i;
    }
    else
      signup[student_num] = i;
  }
  vector<pair<string,int>> slist (signup.begin(), signup.end());
  sort(slist.begin(), slist.end(), [](auto& a, auto& b) { return a.second < b.second;});

  auto en = k;
  if(k > slist.size())
    en = slist.size();

  for(int i=0; i<en; ++i) {
    auto [x, _] = slist[i];
    cout << x << '\n';
  }
}
