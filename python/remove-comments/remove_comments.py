#!/usr/bin/python3

## @package remove_comments.py
#   删除代码文件中的所有注释，支持C，CPP，Java
#   @bug    1. 会匹配到字符串内部的注释符号\
#               "hello /* comments */ world"  -> "hello  world"
#           2. 换行符会产生影响
#               // #define f(x)     \
#                      ((x) * (x))          ->  ((x) * (x)) 
#           
#   @usage  python3 remove_comments.py <src path> <dst path>
#           ./remove_comments.py <src path> <dst path>

import sys
import os
import shutil
import re

## 查找目录中的代码文件
# @param    path    代码文件目录
# @return   代码文件的迭代对象
def _find_code_file(path):
    fname_rules = r'.*?\.(h|c|hh|cpp|java)$'
    for root, dirs, files in os.walk(path):
        for name in files:
            if re.match(fname_rules, name):
                tmp = os.path.join(root, name)
                yield tmp


## 去除代码文件中的注释
# @param    src_fname   源文件名
# @param    dst_fname   目标文件名
def _do_remove_comments(fname):
    rules = r'((?<=\n)|^)[ \t]*\/\*(\s|.)*?\*\/\n?|\/\*(\s|.)*?\*\/|((?<=\n)|^)[ \t]*\/\/[^\n]*\n|[ \t]*\/\/[^\n]*'
    src_file = open(fname, 'r')
    dst_file = open(fname+'.tmp', 'w+')
    code = src_file.read()
    code = re.sub(rules, '', code)
    dst_file.write(code)
    src_file.close()
    dst_file.close()
    shutil.move(fname+'.tmp', fname)


## 删除目录中代码文件的注释
# @param    src_fpath   源文件目录
# @param    dst_fpath   目标文件目录
def do_remove_comments(src_fpath, dst_fpath):
    if not os.path.exists(src_fpath):
        print ("[error]: src_fpath not exist!")
    if os.path.exists(dst_fpath):
        shutil.rmtree(dst_fpath)
    shutil.copytree(src_fpath, dst_fpath)
    for name in _find_code_file(dst_fpath):
         _do_remove_comments(name)


if __name__ == "__main__":
    do_remove_comments(sys.argv[1], sys.argv[2])