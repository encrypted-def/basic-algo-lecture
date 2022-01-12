// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/****************
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k,l;
    unordered_map<string ,int > hash;
    cin >> k >> l;
    string num;
    queue<pair<string,int>> Q;
    for (int i = 1; i <= l; ++i) {
        cin >> num;
        Q.push({num,i});
        if (hash.find(num) != hash.end()) { // 수강 신청 최초 클릭
            hash[num] = i;
        } else { // 다시 수강 신청 버튼을 클릭 했을 때 hash 값을 새로운 인덱스로 치환
            hash[num] = i;
        }
    }
    int cnt = 0;
    while (!Q.empty()) {
        string n = Q.front().first;
        int idx = Q.front().second;
        Q.pop(); // 수강 신청 순서 대로 queue 에서 꺼냄
        if (hash[n] == idx) { //
            cout << n << '\n';
            cnt++;
        }
        if (cnt == k) break;
    }
}