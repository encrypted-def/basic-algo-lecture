// Authored by : unluckyjung
// Co-authored by : -
// http://boj.kr/a84f083cdee3436f9f46acdef175e55f

#include<bits/stdc++.h>
#define ll long long
using namespace std;

stack<int> s;
int n;
ll answer;

void view_check(ll building) {
	while (!s.empty()) {
		if (building >= s.top()) s.pop();
		else {
			answer += s.size();
			return;
		}
	}
}

void solve() {
	ll building;
	while (n--) {
		cin >> building;

		if (!s.empty()){
			if (building < s.top()) answer += s.size();
			else view_check(building);
		}
		s.push(building);
	}
	cout << answer;
}

void input() {
	cin >> n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	input();
	solve();
	return 0;
}