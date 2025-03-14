// Authored by : audwns27
// Co-authored by : -
// http://boj.kr/786d00d372ac47c8807c9c49e9e8bca7
#include <bits/stdc++.h>
using namespace std;

int ttoi (string time){ // HH:MM 형태의 string을 integer 값으로 변경해주는 함수
  int t = 0;
  string h, m;

  h = time.substr(0,2);
  m = time.substr(3,2);

  t = (60 * stoi(h)) + stoi(m);
  return t;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;

  string S, E, Q;
  cin >> S >> E >> Q;

  int st_t, end_t, stream_t;
  st_t = ttoi(S);
  end_t = ttoi(E);
  stream_t = ttoi(Q);

  unordered_set<string> st_list; // 개강총회 시작전에 입장한 학회원들
  unordered_set<string> atd_list; // 최종 출석자 리스트

  while(true){
    string c_time, name;
    cin >> c_time >> name;
    if(cin.eof() == true) break;

    if(ttoi(c_time) <= st_t){
      st_list.insert(name);
    }
    else if(ttoi(c_time) >= end_t && ttoi(c_time) <= stream_t){
      if(st_list.find(name) != st_list.end()) {
      atd_list.insert(name);
      }
    }
  }

  cout << atd_list.size() << "\n";
  return 0;
}
