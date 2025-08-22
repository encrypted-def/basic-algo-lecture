// Authored by : kwh0420
// Co-authored by : -
// http://boj.kr/c7ea698f2efe4d9ba0fed958631073e5
#include <bits/stdc++.h>
using namespace std;

string string1;
string string2;
map<char,int> dna; // 각 유전자의 삽입 비용을 저장하는 매핑
int A, C, G, T;   // 각 유전자의 삽입 비용
int idx;          // 탐색용 인덱스
int total;        // string2 전체를 구성하는 데 필요한 총 비용
int maxval;       // string1 내에서 string2의 연속 부분 문자열과 일치하는 부분 중, 가장 큰 비용 합

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> string1;
  cin >> string2;
  
  cin >> A >> C >> G >> T;
  
  // 유전자 비용 매핑
  dna['A'] = A;
  dna['C'] = C;
  dna['G'] = G;
  dna['T'] = T;
  
  // string2 전체를 만드는 데 드는 총 비용 계산
  for (int i = 0; i < string2.length(); i++) 
    total += dna[string2[i]];
  
  
  // string1의 모든 연속 부분 문자열을 확인하면서,
  // string2의 부분 문자열이 될 수 있는 경우의 비용 합을 구함
  while (idx < string1.length()) {
    int sum = 0;
    int temp = idx; 
    for (int j = 0; j < string2.length(); j++) {
      if (string1[idx] == string2[j]) {
        sum += dna[string1[idx]];
        idx++;
      }
    }
    idx = temp + 1;
    maxval = max(maxval, sum);
  }
  
  // string2 전체 비용에서 이미 string1에 포함된 부분 문자열의 최대 비용을 빼면
  // 추가로 투자해야 할 최소 비용이 됨
  cout << total - maxval;
}
