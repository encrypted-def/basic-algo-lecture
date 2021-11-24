// Authored by : std-freejia
// https://www.acmicpc.net/submit/2504/35738818
#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.ignore(0);

    getline(cin, str);

    bool check = true; // 짝이 맞는 괄호인지 짝이 안맞는 비정상 괄호인지 체크

    int sum = 0; // 누적해서 더해질 값
    int num = 1; // 곱해질 값

    for(int i = 0; i < str.length(); i++){ // 괄호가 틀린 경우를 필터링

        if(str[i] == '(' || str[i] == '[') {
            s.push(str[i]); continue;
        }
        else if(str[i] == ']' && s.size() > 0){
            if(s.top() == '[') {
                s.pop();
                continue;
            }
        }
        else if(str[i] == ')' && s.size() > 0){
            if(s.top() == '(') {
                s.pop();
                continue;
            }
        }
        check = false; break;
    }

    if(!check || !s.empty()){
        cout << '0';
        return 0;
    }

    while(1){ // 스택이 비어 있도록 처리
        if(s.empty()) break;
        s.pop();
    }

    for(int i = 0; i < str.length(); i++){

        if(str[i] == '('){
            s.push(str[i]);
            num *= 2; // 여는 괄호들이 겹치면 2배가 된다.
        }
        else if(str[i] == ')'){

            if(str[i-1] == '('){ // 직전 괄호가 여는 괄호였다면
                sum += num;
            }
            s.pop();
            num /= 2;  // 괄호 () 한쌍이 제거됬으니까 곱해질 값을 /2 해준다.
        }
        else if(str[i] == '['){
            s.push(str[i]);
            num *= 3;
        }
        else if(str[i] == ']'){

            if(str[i-1] == '['){ // 직전 괄호가 여는 괄호였다면
                sum += num;
            }
            s.pop();
            num /= 3;  // 괄호 [] 한쌍이 제거됬으니까 곱해질 값을 /3 해준다.
        }
    }

    cout << sum;

    return 0;
}