// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/45a28ac784dd40769670ad654bb67f81
#include <bits/stdc++.h>
using namespace std;

vector<int> f, ans;
string a, w, s;
int cnt[64];
int oa[257], ma[257];

vector<int> failure(){
  vector<int> f(w.size());
  int j = 0;
  for(int i = 1; i < w.size(); i++){
    while(j > 0 && w[i] != w[j]) j = f[j-1];
    if(w[i] == w[j]) f[i] = ++j;
  }
  return f;
}

void solve(){
  int as = a.size();
  for(int k = 0; k < as; k++){
    for(int i = 0; i < as; i++)
      ma[a[i]] = (oa[a[i]] + k)%as;

    int j = 0;
    for(int i = 0; i < s.size(); i++){
      while(j > 0 && oa[s[i]] != ma[w[j]]) j = f[j-1];
      if(oa[s[i]] == ma[w[j]]) j++;
      if(j == w.size()){
        j = f[j-1];
        cnt[k]++;
      }
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    vector<int> ().swap(f);
    vector<int> ().swap(ans);
    fill(cnt, cnt + 64, 0);

    cin >> a >> w >> s;
    for(int i = 0; i < a.size(); i++) oa[a[i]] = i;

    f = failure();
    solve();

    for(int k = 0; k < a.size(); k++)
      if(cnt[k] == 1) ans.push_back(k);

    if(ans.size() == 0) cout << "no solution\n";
    else if(ans.size() == 1)
      cout << "unique: " << ans[0] << '\n';
    else {
      cout << "ambiguous: ";
      for(int a : ans) cout << a << ' ';
      cout << '\n';
    }
  }
}
/*
oa와 ma는 각각 원 알파벳과 변형된 알파벳의 순서를 의미한다.
oa와 ma는 char 변수로 인덱싱하여 해당 글자의 알파벳 번호를 반환한다.

알파벳의 문자들엔 번호를 매긴다.
이는 48번째 줄을 통해 부여되며,
1 이상, a.size() 이하의 값을 갖는다.
이후 solve()의 24-26번째 줄을 통해서
oa를 k만큼 쉬프트한 값을 ma에 할당한다.

이렇게 각 문자를 번호로 바꾸며,
암호문 내에 원문 패턴이 몇 번 나오는지 KMP로 카운트하여
ans 벡터에 넣고 'cnt[k] == 1'인 k를 출력 형식에 맞춰 출력한다.
*/
