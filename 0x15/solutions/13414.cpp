// Authored by : diyamea
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/ccd33d92a6564257b16e6503e29f7400
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int k,l;
  cin >> k >> l;
  unordered_map<string, int> signup{};
  for(int i=0; i<l; ++i) {
    string student_num;
    cin >> student_num;
    signup[student_num] = i;
  }
  vector<pair<string,int>> slist (signup.begin(), signup.end());
  // 이 문법이 익숙하지 않으면 익명 함수 or 람다 식 검색
  sort(slist.begin(), slist.end(), [](auto& a, auto& b) { return a.Y < b.Y;});

  int en = min(k, (int)slist.size());

  for(int i = 0; i < en; ++i) 
    cout << slist[i].X << '\n';
}
