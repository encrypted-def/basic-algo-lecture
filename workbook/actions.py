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
      codes = open(file_path + '.cpp', 'r', encoding="UTF-8").read()
      if codes == txt:
        prob_table += f'| {prob_id} | {prob_name} | - |\n'        
      else:
        solution_num += 1
        code_attr = f'[정답 코드]({file_path}.cpp)'
        MAX_DIFFERENT_SOLUTION = 9
        for i in range(1, MAX_DIFFERENT_SOLUTION+1):
          if os.path.exists(file_path+'_'+str(i)+'.cpp'):
            code_attr += f", [별해 {i}]({file_path+'_'+str(i)+'.cpp'})"
        prob_table += f'| {prob_id} | {prob_name} | {code_attr} |\n'
    with open(attr[0]+'.md', 'w', encoding="UTF-8") as f:
      # progress bar
      f.write(f'![100%](https://progress-bar.dev/{solution_num}/?scale={len(problem_infos)}&title=progress&width=500&color=babaca&suffix=/{len(problem_infos)})\n\n')
      f.write(prob_table)
    
# ['0x11', '그리디', 'https://www.acmicpc.net/workbook/view/7320']
def gen_total_workbook(attrs):
  with open('workbook.md', 'w', encoding="UTF-8") as f:
    f.write('''# 문제집 (개정 후 버전)

| 번호 | 주제 |
| :--: | :--: |\n''')
    for attr in attrs:
      if len(attr) < 3: # No workbook
        f.write(f'| {attr[0]} | {attr[1]} |\n')
      else:
        f.write(f'| {attr[0]} | [{attr[1]}]({attr[0]}.md) |\n')

attrs = parse_links()
gen_total_workbook(attrs)
gen_ind_workbook(attrs)