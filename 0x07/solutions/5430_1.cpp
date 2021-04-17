// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/7e8f9d4a76c04f189068ad00cd1d463f

// Without deque
#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, vector<int>& v){
  int cur = 0;
  for(int i = 1; i+1 < tmp.size(); i++)
  {
    if(tmp[i] == ','){
      v.push_back(cur);
      cur = 0;
    }
    else{
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  if(cur != 0)
    v.push_back(cur);
}

void print_result(vector<int>& v){
  cout << '[';
  for(int i = 0; i < v.size(); i++)
  {
    cout << v[i];
    if(i+1 != v.size())
      cout << ',';
  }
  cout << "]\n";
}

int t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    vector<int> v;
    int rev = 0;
    int n;
    string query, tmp;
    cin >> query;
    cin >> n;
    cin >> tmp;
    parse(tmp, v);
    int l = 0, r = n;
    for(char c : query)
    {
      if(c == 'R')
        rev = 1 - rev;
      else{
        if(!rev) l++;
        else r--;
      }
    }
    if(l > r)
      cout << "error\n";
    else{
      vector<int> tmp(v.begin()+l, v.begin()+r);
      if(rev) reverse(tmp.begin(), tmp.end());
      print_result(tmp);
    }
  }
}
