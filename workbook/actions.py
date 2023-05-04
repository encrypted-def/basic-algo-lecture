import os

import requests

pbars = []
# ['0x11', '그리디', 'https://www.acmicpc.net/workbook/view/7320']
def parse_links():
  attrs = []
  with open('links.txt', encoding="UTF-8") as f:
    for line in f:
      attrs.append(line.strip().split(','))
  return attrs

def parse_category():
  category = []
  with open('problems.txt', encoding="UTF-8") as f:
    for line in f:
      category.append(line.strip().split(','))
  return category

def get_problem_info(workbook_url):
  headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.95 Safari/537.36'}
  txt = requests.get(workbook_url, headers=headers).text
  pattern = '/problem/'
  ret = []
  while True:
    x = txt.find(pattern)
    if x == -1: break
    txt = txt[x+9:]
    prob_id, prob_name = '', ''
    i = 0
    while txt[i] in '0123456789':
      prob_id += txt[i]
      i += 1
    if not prob_id: continue
    i += 2
    while txt[i] != '<':
      prob_name += txt[i]
      i += 1
    ret.append((prob_id, prob_name))
  return ret

CATEGORY = ["연습 문제", "기본 문제✔", "기본 문제", "응용 문제✔", "응용 문제"]

# gen 0x00.md to 0x??.md, proper prob_id.cpp for each solution directory
def gen_ind_workbook(attrs, category):
  txt = '''// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/****************
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
}'''
  chapter_idx = 0
  for attr in attrs:
    if len(attr) < 3: # No workbook
      pbars.append("")
      continue
    solution_num = 0
    solution_path = f'../{attr[0]}/solutions/'
    category_idx = 0
    problem_infos = get_problem_info(attr[2])
    prob_table = '| 문제 분류 | 문제 | 문제 제목 | 정답 코드 |\n| :--: | :--: | :--: | :--: |\n'
    for prob_id, prob_name in problem_infos:
      if prob_id in category[chapter_idx]:
        category_idx = category[chapter_idx].index(prob_id)
      file_path = solution_path + prob_id
      if not os.path.exists(file_path + '.cpp'):
        with open(file_path + '.cpp', 'w', encoding="UTF-8") as f:
          f.write(txt)
      try:
        codes = open(file_path + '.cpp', 'r', encoding="UTF-8").read()
      except: # EUC-KR -> UTF-8
        codes = open(file_path + '.cpp', 'r', encoding="EUC-KR").read()
        with open(file_path + '.cpp', 'w', encoding="UTF-8") as fw:
          fw.write(codes)
      if codes[:100] == txt[:100]:
        prob_table += f'| {CATEGORY[category_idx]} | {prob_id} | [{prob_name}](https://www.acmicpc.net/problem/{prob_id}) | - |\n'
      else:
        solution_num += 1
        code_attr = f'[정답 코드]({file_path.replace(" ", "%20")}.cpp)'
        MAX_DIFFERENT_SOLUTION = 9
        for i in range(1, MAX_DIFFERENT_SOLUTION+1):
          if os.path.exists(file_path+'_'+str(i)+'.cpp'):
            code_attr += f", [별해 {i}]({file_path+'_'+str(i)+'.cpp'})"
        prob_table += f'| {CATEGORY[category_idx]} | {prob_id} | [{prob_name}](https://www.acmicpc.net/problem/{prob_id}) | {code_attr} |\n'
    with open(attr[0]+'.md', 'w', encoding="UTF-8") as f:
      # progress bar
      f.write(f'# {attr[1]}\n\n')
      pbar = f'![100%](https://progress-bar.dev/{solution_num}/?scale={len(problem_infos)}&title=progress&width=500&color=babaca&suffix=/{len(problem_infos)})'
      pbars.append(pbar)
      f.write(pbar + '\n\n')
      f.write(f'[문제집 링크]({attr[2]})\n\n')
      f.write(prob_table)
    chapter_idx += 1
    
# ['0x11', '그리디', 'https://www.acmicpc.net/workbook/view/7320']
def gen_total_workbook(attrs):
  with open('../workbook.md', 'w', encoding="UTF-8") as f:
    f.write('''# 문제집 설명

일부 단원을 제외하면 각 단원에 대응되는 문제집이 있습니다. 설령 이론을 잘 이해했더라도 문제를 풀어내지 못한다면 아무런 의미가 없기 때문에 반드시 문제를 많이 풀어보셔야 합니다.

문제집의 문제는

- **연습 문제** : 강의 내에서 같이 풀어본 문제

- **기본 문제** : 특별한 응용 없이 강의에서 다룬 내용을 바탕으로 해결할 수 있는 문제

- **응용 문제** : 약간의 응용이 필요해서 난이도가 있는 문제

로 분류됩니다. **기본 문제**, **응용 문제** 중에서 특히 풀어보길 권장하는 문제는 **✔**으로 표시를 해두었습니다.

먼저 강의 내에 있는 제 코드를 참고하지 않고 **연습 문제**를 풀어봅니다. 그 후에 **기본 문제✔**까지는 풀어보시는걸 강력하게 권장합니다. **기본 문제✔**를 풀 때 아예 풀이를 모르겠다면 아직 학습이 부족한 상태이니 강의를 다시 확인하실 필요가 있습니다.

**기본 문제✔**를 풀 때 풀이는 떠올릴 수 있지만 구현에서 문제가 생기는 경우라면 정답 코드를 참고해서 구현법을 익힌 후 다른 **기본 문제**를 풀이 참고 없이 풀면서 구현력을 기르시는걸 추천드립니다.

**기본 문제✔**를 풀 때 큰 어려움이 없다면 **응용 문제✔**도 확인해서 문제 해결 능력을 길러보시는걸 추천드립니다. **응용 문제✔** 분류의 문제들은 다소 발상이 어렵거나 새로운 테크닉을 필요로 할 수 있기 때문에 30분-1시간 정도 고민한 후에도 풀이를 모르겠다면 정답 코드나 풀이를 확인해도 괜찮습니다. 그러나 풀이만 확인하고 끝내는 것이 아니고 반드시 풀이를 바탕으로 혼자 힘으로 구현해보는 것을 추천드립니다.

**응용 문제✔**를 모두 해결했다면 우선 다음 단원으로 넘어가고, 나중에 완강을 한 후 남은 **응용 문제**를 풀이 참고 없이 도전해보는걸 추천드립니다.

정리하자면 문제집에서 **연습 문제**, **기본 문제✔**, **응용 문제✔** 까지 풀고 다음 단원으로 넘어가는걸 추천드립니다. **응용 문제✔**는 풀이를 참고해도 괜찮지만 **연습 문제**, **기본 문제✔**는 강의의 내용을 잘 이해했다면 풀이를 참고하지 않고 구현할 수 있기 때문에 혼자 힘으로 풀어보길 권장합니다. 만약 **응용 문제✔**를 푸는데에 어려움이 있다면 **응용 문제✔** 대신 **기본 문제**를 더 풀고 다음 단원으로 넘어가도 괜찮습니다.

# 문제집
| 번호 | 주제 | 진행도 |
| :--: | :--: | :--: |\n''')
    for attr, pbar in zip(attrs, pbars):
      if len(attr) < 3: # No workbook
        f.write(f'| {attr[0]} | {attr[1]} | |\n')
      else:
        f.write(f'| {attr[0]} | [{attr[1]}](workbook/{attr[0].replace(" ", "%20")}.md) | {pbar} |\n')

attrs = parse_links()
category = parse_category()
gen_ind_workbook(attrs, category)
gen_total_workbook(attrs)
