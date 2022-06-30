#!/usr/bin/python3

import os
import re

keyword_url = {
    'map':'',
    '字符串':'',
    '完全二叉树':'',
    'AVL树':'',
    '动态规划':'',
    '贪心':'',
    '背包问题':'',
    '并查集':'',
    'BST':'',
    '前中后序遍历':'',
    'hash数组':'',
    '层序遍历':'https://github.com/ultraji/notebook_algorithm/blob/master/note/%E6%A0%91%E7%9A%84%E9%81%8D%E5%8E%86.md', 
    '快排':'',
    'DFS':'',
    'BFS':'',
    'Dijkstra算法':'https://github.com/ultraji/notebook_algorithm/blob/master/note/Dijkstra%E7%AE%97%E6%B3%95.md'
}

## 查找目录中的代码文件（按文件名排序）
# @param    path    代码文件目录
# @return   代码文件的迭代对象
def _find_code_file(path):
    fname_rules = r'.*?\.(h|c|hh|cpp|java)$'
    files = os.listdir(path)
    files.sort()
    for name in files:
        if re.match(fname_rules, name):
            tmp = os.path.join(path, name)
            yield tmp

## 创建表格一行
# @param    path    解题CPP文件路径
# @return   markdown格式的一行表格
def _creat_table_row(path):
    row_str = ""
    tmp = open(path, 'r')
    tmp.readline()
    id_title = str(tmp.readline())
    keywords = str(tmp.readline())
    tmp.close()
    if re.match(r'[0-9]{4}[\. ]', id_title):
        id, title = id_title[:4], id_title[5:-1]
        row_str = "| "+ id + " | " + title + " | " + "[Accepted](" + path + ")" + " | "
        if keywords.find("keywords:") != -1:
            for keyword in keywords[10:-1].split('、'):
                print(keyword)
                if keyword in keyword_url:
                    row_str += "[" + keyword + "](" + keyword_url[keyword] + ")" + "、"
        row_str +=  " |\n"
    return row_str

## 创建4栏表格
# @param    path    文件夹路径
# @return   void
def _creat_table(table_name, table_tab, path):
    readme = open("README.md", 'a')
    readme.write("## " + table_name + "\n\n")
    for tab in table_tab:
        readme.write("| " + tab + " ")        
    readme.write("|\n")
    readme.write("|---|---|---|---|\n")    
    for fp in _find_code_file(path):
        readme.write( _creat_table_row(fp) )
    readme.write("\n")
    readme.close()


with open("README.md", 'w') as readme:
    readme.write("## 浙江大学PAT题解(C/C++/Python)\n\n只为写一份简单易懂的代码。\n")

_creat_table("PAT (Advanced Level)", ["ID","Title","C/C++","Keywords"], "CPP/PAT_A")
_creat_table("PAT (Basic Level)", ["ID","Title","C/C++","Keywords"], "CPP/PAT_B")