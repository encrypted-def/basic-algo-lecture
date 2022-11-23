// Authored by : audwns27
// Co-authored by : -
// http://boj.kr/786d00d372ac47c8807c9c49e9e8bca7

#include <bits/stdc++.h>

int timetoint (string time){	// HH:MM 형태의 string을 integer 값으로 변경해주는 함수
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

	int start_time, end_time, stream_time;
	start_time = timetoint(S);
	end_time = timetoint(E);
	stream_time = timetoint(Q);

	unordered_set<string> start_list;	// 개강총회 시작전에 입장한 학회원들
	unordered_set<string> attend_list;	// 최종 출석자 리스트

	while(true){
		string time, name;
		cin >> time >> name;
		if(cin.eof() == true) break;

		if(timetoint(time) <= start_time){
			start_list.insert(name);
		}
		else if(timetoint(time) >= end_time && timetoint(time) <= stream_time){
			if(start_list.find(name) != start_list.end()) {
				attend_list.insert(name);
			}
		}		
	}

	cout << attend_list.size() << "\n";
	return 0;
}

/*

   1. 개강총회 시작 전 채팅 기록이 있는 학생들을 start_list에 insert

   2. 개강총회 종료후 부터 스트리밍 종료 시간 전까지 채팅기록이 있는 학생들중 start_list에 존재하는 학생들을 최종 출석리스트에 추가

*/


