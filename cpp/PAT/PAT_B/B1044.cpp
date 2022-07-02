/*
1044 火星数字 （20 分）
火星人是以 13 进制计数的：
地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，
请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。

输入样例：
4
29
5
elo nov
tam
输出样例：
hel mar
may
115
13
*/

#include <iostream>
using namespace std;
string ge[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shi[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(){
    int n, num;
    string s;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        if(isdigit(s[0])){
            num = atoi(s.c_str());
            if(num >= 13 && num%13 != 0){
                cout << shi[num/13] << ' ' << ge[num%13] << endl;
            }else if(num >= 13 && num%13 == 0){
                cout << shi[num/13] << endl;
            }else{
                cout << ge[num%13] << endl;
            }
            
        }else{
            int pos, i, j;
            string a = s, b = s;
            if((pos = s.find(' ')) != -1){
                a = s.substr(0, pos);
                b = s.substr(pos+1);
            }
            for(i = 0; i < 13 && a != shi[i]; i++);
            for(j = 0; j < 13 && b != ge[j]; j++);
            num = i % 13 * 13 + j % 13;
            cout << num << endl;
        }
    }
    return 0;
}