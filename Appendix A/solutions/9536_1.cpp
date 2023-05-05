// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/c6e7465dfe8448a39b394e9f48c57aa0
#include <bits/stdc++.h>
using namespace std;

string rec_sound, input, s;
stringstream ss;
unordered_map<string, bool> um;

void solve() {
  getline(cin, rec_sound);
  getline(cin, input);
  while(input != "what does the fox say?") {
    ss = stringstream(input);
    ss >> s >> s >> s;
    um[s] = 1;
    getline(cin, input);
  }

  ss = stringstream(rec_sound);
  while(ss >> s)
    if(!um[s]) cout << s << ' ';
  cout << '\n';
  um.clear();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, input);
  int t = stoi(input);

  while(t--) solve();
}
/*
해쉬(unordered_map)와 stringstream을 이용한 풀이입니다.
stringstream은 공백을 분리해서 문자열을 보내줍니다.
14-19번째 줄은 입력받은 동물의 소리를 구분해서 해쉬에 기록합니다.

이후 녹음했던 소리를 stringstream으로 생성하고
이를 문자열에 흘려보내면서 해쉬에 없는 소리는 출력합니다.
이후 해쉬를 비워줍니다(25번째 줄).

32-33번째 줄에선 cin.ignore()를 쓰지 않기 위하여
getline 후 stoi로 t 값을 받습니다.
*/