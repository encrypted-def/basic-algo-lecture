// Authored by : charmkekenji
// Co-authored by : -
// http://boj.kr/94d087bf57044bcb9bb97c5a1caca630
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
pair<int, int> students[500'000]; // first: 학생의 키, second: 최소 등수
multiset<int> teams; // 구성된 각 팀의 크기(수강생 수)를 원소로 가진다.
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> students[i].first >> students[i].second;
	}

	sort(students, students + N);

	for (int i = N - 1; i >= 0; --i) {
		auto it = teams.lower_bound(students[i].second);
		if (it == teams.begin())
			teams.insert(1);
		else {
			it = prev(it);
			int teamSize = *it;
			teams.erase(it);
			teams.insert(teamSize + 1);
		}
	}

	cout << teams.size();
}

/*
큰 학생부터 작은 학생 순서로 팀을 만들면, 팀에 들어가는 학생의 등수는 (팀의 크기 + 1)이다.
기존에 있는 모든 팀의 크기가 최소 등수 이상이면 새로 팀을 만들고, 아니면 최소 등수 미만의 팀 중 가장 큰 팀에 추가한다.
*/