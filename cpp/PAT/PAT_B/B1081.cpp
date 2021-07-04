/*
1081 检查密码 （15 分）
本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。该网站要求用户设置的密码必须由不少于6个字
符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。

输入格式：
输入第一行给出一个正整数 N（≤ 100），随后 N 行，每行给出一个用户设置的密码，为不超过 80 个字符的非空字
符串，以回车结束。

输出格式：
对每个用户的密码，在一行中输出系统反馈信息，分以下5种：

如果密码合法，输出Your password is wan mei.；
如果密码太短，不论合法与否，都输出Your password is tai duan le.；
如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。

输入样例：
5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6

输出样例：
Your password is tai duan le.
Your password needs shu zi.
Your password needs zi mu.
Your password is wan mei.
Your password is tai luan le.
*/

#include <iostream>
#include <cstring>
#include <regex>
using namespace std;

char match[3][20] = {"^[A-Za-z0-9\\.]+", "^[0-9\\.]+", "^[A-Za-z\\.]+"};
char outStr[3][20] = {"is wan mei", "needs zi mu", "needs shu zi"};

int main()
{
    int n;
    char psd[82], resStr[50], t;
    scanf("%d%c", &n, &t);
    while(n--){
        memset(psd, 0, 82);
        fgets(psd, 82, stdin);
        psd[strlen(psd) - 1] = 0;
        if(strlen(psd) < 6){
            sprintf(resStr, "Your password is tai duan le.");
        }else{
            sprintf(resStr, "Your password is tai luan le.");
            for(int i = 0; i < 3; i++){
                regex reg(match[i]);
                if(regex_match(psd, reg)){
                    sprintf(resStr, "Your password %s.", outStr[i]);
                }
            }
        }
        puts(resStr);
    }
    return 0;
}