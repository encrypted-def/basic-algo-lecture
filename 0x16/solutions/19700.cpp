// Authored by : charmkekenji
// Co-authored by : -
// http://boj.kr/94d087bf57044bcb9bb97c5a1caca630
#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N;
pair<int, int> students[500'000]; // first: �л��� Ű, second: �ּ� ���
multiset<int> teams; // ������ �� ���� ũ��(������ ��)�� ���ҷ� ������.
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
ū �л����� ���� �л� ������ ���� �����, ���� ���� �л��� ����� (���� ũ�� + 1)�̴�.
������ �ִ� ��� ���� ũ�Ⱑ �ּ� ��� �̻��̸� ���� ���� �����, �ƴϸ� �ּ� ��� �̸��� �� �� ���� ū ���� �߰��Ѵ�.
*/