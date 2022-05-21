// Authored by : seondal
// Co-authored by : -
// http://boj.kr/4ad636df8ee141a1bb0fd0d9cbcf0312

#include <bits/stdc++.h>

using namespace std;

int N;
char video[64][64];
vector<char> v;

bool check(int n, int x, int y) {   // (x,y) 부터 n개 크기 종이가 같은 숫자로 채워졌는지 확인
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            if(video[i][j] != video[x][y])
                return false;
    
    return true;
}

void recur(int n, int x, int y) {
    if(check(n,x,y)) {
        v.push_back(video[x][y]);
        return;
    }
    
    int next = n/2;
    for(int i=x; i < x+n; i = i+next) {
        for(int j=y; j < y+n; j = j+next) {
            v.push_back('(');
            recur(next, i, j);
            v.push_back(')');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> video[i][j];
    
    // 재귀
    recur(N, 0, 0);
    
    //출력
    if(v.size()==1) {
        // 답이 0이나 1 하나인 경우.. 괄호때문에 예외처리..
        cout << v[0];
    }
    else {
        cout << "(";
        for(int i=0; i<v.size(); i++) {
            if(v[i]=='(') {
                if(v[i+1] == '(') cout << "(";
            }
            else if(v[i]==')') {
                if(v[i+1]==')') cout << ")";
            }
            else cout << v[i];
        }
        cout << ")";
    }
    
    return 0;
}

/*
 재귀를 사용하는 방식은 같으나 현재 영역이 압축 가능하면 true를 리턴하는 check 함수를 이용한 풀이입니다..!
 풀이 : https://whkakrkr.tistory.com/entry/BOJ-S1-%EB%B0%B1%EC%A4%80-1992%EB%B2%88-%EC%BF%BC%EB%93%9C%ED%8A%B8%EB%A6%AC-83
 */
