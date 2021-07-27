import requests, os

# ['0x11', '그리디', 'https://www.acmicpc.net/workbook/view/7320']
def parse_links():
  attrs = []
  with open('links.txt', encoding="UTF-8") as f:
    for line in f:
      attrs.append(line.strip().split(','))
  return attrs

def get_problem_info(workbook_url):
  txt = requests.get(workbook_url).text
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

# gen 0x00.md to 0x??.md, proper prob_id.cpp for each solution directory
def gen_ind_workbook(attrs):
  txt = '''// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/****************
#include <bits/stdc++.h>
using namespace std;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
}'''
  for attr in attrs:
    if len(attr) < 3: # No workbook
      continue
    solution_num = 0
    solution_path = f'../{attr[0]}/solutions/'

    problem_infos = get_problem_info(attr[2])
    prob_table = '| 문제 | 문제 제목 | 정답 코드 |\n| :--: | :--: | :--: |\n'
    for prob_id, prob_name in problem_infos:
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
      if codes == txt:
        prob_table += f'| {prob_id} | [{prob_name}](https://www.acmicpc.net/problem/{prob_id}) | - |\n'        
      else:
        solution_num += 1
        code_attr = f'[정답 코드]({file_path}.cpp)'
        MAX_DIFFERENT_SOLUTION = 9
        for i in range(1, MAX_DIFFERENT_SOLUTION+1):
          if os.path.exists(file_path+'_'+str(i)+'.cpp'):
            code_attr += f", [별해 {i}]({file_path+'_'+str(i)+'.cpp'})"
        prob_table += f'| {prob_id} | [{prob_name}](https://www.acmicpc.net/problem/{prob_id}) | {code_attr} |\n'
    with open(attr[0]+'.md', 'w', encoding="UTF-8") as f:
      # progress bar
      f.write(f'# {attr[1]}\n\n')
      f.write(f'![100%](https://progress-bar.dev/{solution_num}/?scale={len(problem_infos)}&title=progress&width=500&color=babaca&suffix=/{len(problem_infos)})\n\n')
      f.write(f'[문제집 링크]({attr[2]})\n\n')
      f.write(prob_table)
    
# ['0x11', '그리디', 'https://www.acmicpc.net/workbook/view/7320']
def gen_total_workbook(attrs):
  with open('../workbook.md', 'w', encoding="UTF-8") as f:
    f.write('''# 문제집 (개정 후 버전)
| 번호 | 주제 |
| :--: | :--: |\n''')
    for attr in attrs:
      if len(attr) < 3: # No workbook
        f.write(f'| {attr[0]} | {attr[1]} |\n')
      else:
        f.write(f'| {attr[0]} | [{attr[1]}](workbook/{attr[0]}.md) |\n')
    f.write('''
# 문제집 (개정 전 버전)
| 번호 | 주제 |
| :---: | :---: |
| 0x01 | [시간복잡도와 기초 지식](https://www.acmicpc.net/workbook/view/7286) |
| 0x02 | [배열과 연결 리스트](https://www.acmicpc.net/workbook/view/7287) |
| 0x03 | [스택, 큐, 덱](https://www.acmicpc.net/workbook/view/7288) |
| 0x04 | [스택 1(수식의 괄호 쌍)](https://www.acmicpc.net/workbook/view/7289) |
| 0x05 | [BFS, DFS](https://www.acmicpc.net/workbook/view/7290) |
| 0x06 | [재귀](https://www.acmicpc.net/workbook/view/7291) |
| 0x07 | [백트래킹, 시뮬레이션](https://www.acmicpc.net/workbook/view/7292) |
| 0x08 | [정렬](https://www.acmicpc.net/workbook/view/7293) |
| 0x09 | [다이나믹 프로그래밍](https://www.acmicpc.net/workbook/view/7294) |
| 0x0A | [그리디](https://www.acmicpc.net/workbook/view/7295) |
| 0x0B | [수학](https://www.acmicpc.net/workbook/view/7296) |
| 0x0C | [이분탐색](https://www.acmicpc.net/workbook/view/7297) |
| 0x0D | [해쉬, 이진 검색 트리, 힙](https://www.acmicpc.net/workbook/view/7298) |
| 0x0E | [문자열(KMP, 라빈 카프)](https://www.acmicpc.net/workbook/view/7299) |
| 0x0F | [그래프](https://www.acmicpc.net/workbook/view/7300) |
| 0x10 | [트리](https://www.acmicpc.net/workbook/view/7301) |
| 0x11 | [위상 정렬](https://www.acmicpc.net/workbook/view/7302) |
| 0x12 | [최소 신장 트리](https://www.acmicpc.net/workbook/view/7303) |
| 0x13 | [플로이드 알고리즘](https://www.acmicpc.net/workbook/view/7304) |
| 0x14 | [다익스트라 알고리즘](https://www.acmicpc.net/workbook/view/7305) |    
''')

attrs = parse_links()
gen_total_workbook(attrs)
gen_ind_workbook(attrs)