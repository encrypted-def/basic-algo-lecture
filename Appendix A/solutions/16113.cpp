// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/5c4deba6615742479d05f71069754f6a
#include <bits/stdc++.h>
using namespace std;

const string NUMBERS[10][5] = {
    {"###", "#.#", "#.#", "#.#", "###"}, // 0
    {"#", "#", "#", "#", "#"},           // 1
    {"###", "..#", "###", "#..", "###"}, // 2
    {"###", "..#", "###", "..#", "###"}, // 3
    {"#.#", "#.#", "###", "..#", "..#"}, // 4
    {"###", "#..", "###", "..#", "###"}, // 5
    {"###", "#..", "###", "#.#", "###"}, // 6
    {"###", "..#", "..#", "..#", "..#"}, // 7
    {"###", "#.#", "###", "#.#", "###"}, // 8
    {"###", "#.#", "###", "..#", "###"}, // 9
};

int n;
string s, b[5];
vector<string> splitted_str[5];

vector<string> split(string& s, vector<int>& bl_idx) {
  vector<string> ret;
  int pos = 0;
  for (int nxt_pos : bl_idx) {
    if (nxt_pos - pos > 0)
      ret.push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + 1; // 1: 구분자 최소 크기
  }
  ret.push_back(s.substr(pos, s.size() - pos));
  return ret;
}

void analyze_array(int idx) {
  for (int no = 0; no < 10; no++) {
    bool is_found = 1;
    for (int i = 0; i < 5; i++) {
      if (splitted_str[i][idx] == NUMBERS[no][i]) continue;
      is_found = 0; break;
    }
    if (!is_found) continue;
    cout << no; return;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  n /= 5;

  for (int i = 0; i < 5; i++)
    b[i].resize(n);

  int idx = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < n; j++)
      b[i][j] = s[idx++];
  
  vector<int> bl_idx;
  for (int j = 0; j < n; j++) {
    bool is_all_blank = 1;
    for (int i = 0; i < 5; i++)
      if (b[i][j] != '.') is_all_blank = 0;
    if (is_all_blank) bl_idx.push_back(j);
  }

  for (int i = 0; i < 5; i++)
    splitted_str[i] = split(b[i], bl_idx);

  for (int idx = 0; idx < splitted_str[0].size(); idx++)
    analyze_array(idx);
}
/*
문자열 s에는 입력으로 주어지는 시그널을 받는다.
이를 5줄로 쪼개서 문자열 배열 b에 넣는다(58-61번째 줄).

bl_idx는 공백이 한 줄로 나오는 인덱스를 저장한다(63-69번째 줄).
bl_idx를 활용하여 문자열 벡터 splitted_str로 각 행을 구분한다(71-72번쨰 줄).

split 함수는 강의의 구현을 응용한다.
nxt_pos를 find로 찾는 게 아니라
이전에 기록한 bl_idx에서 받아서 구분한다.
이때, 마지막으로 확인된 bl_idx에는 size에 해당하는 인덱스가 없으므로
32번째 줄과 같이 substr을 하나 추가한다.

7-18번째 줄에 NUMBERS를 const string으로 선언하고,
이후 반환받은 splitted_str에 대해 analyze_array 함수로
splitted_str과 비교하여 모든 행이 매칭되는 숫자를 출력한다(36-46번째 줄).
*/