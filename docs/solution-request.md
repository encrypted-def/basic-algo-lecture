# 📡문제집 풀이 집단 지성 프로젝트📡

## 설명

문제집에 있는 문제들에 대한 풀이와 코드를 여러 번 요청받았습니다. 문제집에 있는 거의 모든 문제들은 제가 풀어본 문제여서 블로그에 풀이가 있지만 심하게는 거의 4-5년전에 작성한 코드여서 코드가 깔끔하지 않습니다.

그렇다고 해서 문제집에 있는 문제들을 전부 새로 푸는건 현실적으로 불가능하기 때문에 방법을 찾아 고심하던 중 묘수가 떠올라 **여러분의 도움**을 받고자 합니다.

각 단원의 디렉토리에 들어가보면 *solutions*라는 이름의 디렉토리가 있습니다. 해당 디렉토리에는 각 문제들에 대응되는 cpp 파일이 존재합니다. 해당 cpp 파일에 코드를 작성해서 여러분들의 훌륭한 코드를 pull request 해주세요. pull request를 master branch에 바로 날려주시면 됩니다. [pull request를 보내는 방법](https://wayhome25.github.io/git/2017/07/08/git-first-pull-request-story/)

아래는 코드 예시입니다.

```cpp
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/239db99c29924302b0a9237910e0a26d
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << a + b;
}
```

## 규칙

관리의 편의와 통일성을 위해 PR 규칙을 엄격하게 적용할 예정입니다. 미리 양해 부탁드립니다.

### 필수 - 이 규칙에 위배되는 경우 PR을 거절합니다.

#### 일반

- [규칙1] 타인의 코드를 자신이 작성한 코드인 것 처럼 속여서 PR하면 안됩니다.
- [규칙2] Author 정보와 제출 정보(`http://boj.kr/*****`)를 올바르게 기입해야 합니다. Author 정보는 타인을 사칭하지 않는다면 무엇이어도 상관 없습니다. 그리고 PR을 보낸 코드와 BOJ에 제출된 코드가 일치해야 합니다.
- [규칙3] 한 번의 PR은 하나의 코드만 담고 있어야 합니다. 만약 여러 코드를 작성했고 모두 PR을 하고 싶다면 각 문제에 대해 branch를 따로 두어 여러 개의 PR을 보내야 합니다.
- [규칙4] `Allow edits by maintainers` 옵션을 허용으로 둬야합니다.
- [규칙5] 이미 다른 사람이 등록해서 master branch에 올라간 문제의 코드는 기존의 풀이와 아예 다른 알고리즘 혹은 자료구조를 사용하는 것과 같이 **풀이의 방향이 완벽히 다른 경우에만 PR할 수 있습니다.** 이 경우 이름을 *probID_1.cpp, probID_2.cpp*와 같은 방식으로 지정하셔야 합니다.
- [규칙6] 해당 단원 혹은 이전 단원에서 배운 적 없는 알고리즘으로 해결한 풀이는 ~~등록할 수 없습니다.~~ → 해당 단원의 알고리즘을 *probID.cpp*에 우선적으로 배치한 후 등록합니다.

#### 코딩 컨벤션

- [규칙7] `bits/stdc++.h`를 제외한 다른 헤더파일을 include해서는 안됩니다.
- [규칙8] `using namespace std`를 꼭 써야 합니다.
- [규칙9] `define`, `typedef`는 `#define X first`, `#define Y second`, `typedef long long ll;`만 허용합니다. `#define pb push_back`, `#define all(x) (x).begin(), (x).end()` 등은 사용하지 않습니다.
- [규칙10] 탭은 **공백문자 2개**를 사용해야 합니다.
- [규칙11] BFS 혹은 기타 좌표 개념이 들어가는 문제에서 가로와 세로는 강의에서 설명한 방향을 따라야 합니다.
- [규칙12] 입출력은 C++ stream을 이용해야 하고 `ios::sync_with_stdio(0); cin.tie(0);`을 main 함수의 제일 처음에 써야 하며 `endl`을 사용하지 않아야 합니다.
- [규칙13] `new`, `malloc`과 같은 동적 할당을 사용하지 않아야 합니다.
- [규칙14] 구조체 혹은 클래스 대신 `pair`, `tuple`을 사용해야 합니다. 
- [규칙15] 꼭 실수(`float`, `double`)로 계산을 해야하는 경우가 아니라면 모든 연산은 정수에서 이루어져야 합니다.
- [규칙16] 논리 AND, OR는 `and`, `or` 대신 `&&, ||`으로 작성해야 합니다.
- [규칙17] 문제에 필요한 알고리즘이나 자료구조에 대응되는 STL이 있을 경우 직접 구현하는 대신 STL을 활용해야 합니다.
- [규칙18] 문자열은 `char*` 대신 `string` 으로 처리해야 합니다.

### 권장 - 이 규칙에 위배되는 경우 제가 규칙에 맞게 수정한 후 PR을 진행하지만 수정 사항이 너무 많을 경우 거절할수도 있습니다. 수정할 경우 Author는 그대로 두고 Co-author에 제 닉네임을 추가합니다.

#### 코딩 컨벤션

- [규칙19] 변수와 함수의 이름은 모두 소문자로 작성하는 것을 권장합니다.
- [규칙20] 변수와 함수의 이름은 어느 정도 의미하는 바를 드러내면서도 코드가 간결하도록 7글자 이내로 두는 것을 권장합니다(ex : `cnt, val, ret, score, board, dist`). `hap, gop, su`와 같은 변수는 사용을 자제해주세요.
- [규칙21] 한줄짜리 if, for, while 문에는 중괄호를 쓰지 않는 것을 권장합니다.
- [규칙22] 주석은 꼭 필요한 경우에만 간결하게 작성하는 것을 권장합니다.
- [규칙23] 변수는 전역 변수로 선언하든 지역 변수로 선언하든 상관없습니다. 배열의 경우에는 전역 변수로 선언하는 것을 권장하고 칸 수 또한 `+1 to +10` 정도의 여유를 두는 것을 권장합니다.
- [규칙24] 코드에 불필요한 로직이 없게끔 최대한 정리를 한 후에 PR하는 것을 부탁드립니다.
- [규칙25] 자주 반복되는 루틴은 적절하게 함수로 분리하는 것을 권장합니다. `적절하게`의 기준은 사람마다 다를 수 있기 때문에 강의 내에서 제가 작성했던 코드들을 참고해주세요. ([예시 1](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0D/12100.cpp), [예시 2](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0D/15683.cpp), [예시 3](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0D/18808.cpp))
- [규칙26] 발상이 어렵거나, 해당 단원 혹은 이전 단원에서 배운 적 없는 알고리즘으로 해결했거나, 코드만 보고서는 풀이를 이해하기 어렵다고 판단될 경우 `/* */` 주석을 이용해 코드 하단에 간단하게 풀이를 설명해주시면 감사하겠습니다. ([예시 1](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x11/solutions/11000.cpp), [예시 2](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0F/solutions/7795_1.cpp))


## 마무리

많은 참여 부탁드립니다!!
