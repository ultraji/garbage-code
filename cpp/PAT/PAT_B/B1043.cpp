/*
1043 输出PATest （20 分）
给定一个长度不超过 10^4的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这
样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符
仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 10^4的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT

输出样例：
PATestPATestPTetPTePePee
*/

#include <iostream>
using namespace std;

char a[7] = "PATest";
int cnt[7];

int main()
{
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 6; j++){
            if(s[i] == a[j]){
                cnt[j] ++;
                break;
            }
        }
    }
    while(true){
        bool over = true;
        for(int i = 0; i < 6; i++){
            if(cnt[i] != 0){
                cout << a[i];
                cnt[i] --;
                over = false;
            }
        }
        if(over){
            break;
        }
    }
    return 0;
}
