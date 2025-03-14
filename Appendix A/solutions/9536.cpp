// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/1463c7a3b42b49258cc56aa5bfb088fb
#include <bits/stdc++.h>
using namespace std;

vector<string> sounds, other_sounds, tmp;
string s;

vector<string> split(string &str, string sep) {
  vector<string> ret;
  int pos = 0;
  while(pos < str.size()) {
    int nxt_pos = str.find(sep, pos);
    if(nxt_pos == -1) nxt_pos = str.size();
    if(nxt_pos - pos > 0)
      ret.push_back(str.substr(pos, nxt_pos - pos));
    pos = nxt_pos + sep.size();
  }
  return ret;
}

void solve() {
  getline(cin, s);
  sounds = split(s, " ");

  while(1) {
    getline(cin, s);
    if(s == "what does the fox say?") break;
    tmp = split(s, " ");
    other_sounds.push_back(tmp[2]);
  }

  for(string snd : sounds) {
    bool is_other_sound = 0;
    for(string os : other_sounds) {
      if(os != snd) continue;
      is_other_sound = 1; break;
    }
    if(is_other_sound) continue;
    cout << snd << ' ';
  }
  cout << '\n';
  other_sounds.clear();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  cin.ignore();
  while(t--) solve();
}
/*
10-20번째 줄 split 함수는 강의에서 제시된 구현과 같습니다.
이를 통해 구분된 녹음된 소리는 sounds 변수에 저장합니다(24-25번째 줄).

이후 동물들의 울음소리를 받습니다.
"what does the fox say?" 문자열을 입력 받기 전까지 입력을 받으면서
'<동물> goes <소리>' 포맷에서 <소리>에 해당하는 문자열만
other_sounds에 저장합니다(27-32번째 줄).

이후 녹음된 소리가 기록된 sounds 변수를 돌면서
others_sounds에 해당하지 않는 소리만 출력합니다(34-42번째 줄).
한 테스트케이스가 끝나면 other_sounds 변수는 비워줍니다(44번째 줄).

특별히 51번째 줄과 같이 cin.ignore()를 써야
getline으로 공백문자가 전달되지 않습니다.
*/