/*
1033 旧键盘打字 （20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉
的那些键，打出的结果文字会是怎样？

输入格式：
输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不
超过 10^5 个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、
+（代表上档键）。题目保证第 2 行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.

输出样例：
_hs_s_a_tst
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string err_key, word;
    getline(cin, err_key);
    getline(cin, word);
    // 无坏键情况
    if(err_key == ""){
        cout << word;
        return 0;
    }
    if(err_key.find('+') != -1){
        for(unsigned i = 0; i < word.size(); i++){
            if(isalnum(word[i]) && isupper(word[i])){
                word.erase(i, 1);
                i--;
            }
        }
    }
    for(unsigned i = 0; i < err_key.size(); i++){
        for(unsigned j = 0; j < word.size(); j++){
            if(err_key[i] == word[j]
              || (isalpha(word[j]) && err_key[i] == toupper(word[j])) ){
                word.erase(j, 1);
                j--;
            }
        }
    }
    if(word != ""){
        cout << word;
    }else{
        cout << endl;
    }
    return 0;
}
