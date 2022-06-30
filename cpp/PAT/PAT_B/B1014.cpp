/*
1014. 福尔摩斯的约会 (20)
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英
文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14
个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个
位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED
表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

输出样例：
THU 14:04
*/

#include <iostream>
#include <cstring>

#define clock(c) ((c >= 'A' && c <= 'N') ? c-'A'+10 : c-'0')

const char weekday[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
char str[4][100];

int main(){
    char c1, c2, *p, *q;
    int t = 0;
    for(int i = 0; i < 4; i++){
        fgets(str[i], 100, stdin);
    }
    for(p = str[0], q = str[1]; *p != '\n' && *q != '\n'; p++, q++){
        if(*p >= 'A' && *p <= 'G' && *q == *p ){
            c1 = *p;
            break;
        }
    }
    for(p++, q++; *p != '\n' && *q != '\n'; p++,q++){
        if(((*p >= 'A' && *p <='N')||isdigit(*p))&& *p == *q){
            c2 = *p;
            break;
        }
    }
    for (p = str[2], q = str[3]; !(isalpha(*p) && *p == *q); t++, p++, q++);
    printf("%s %02d:%02d", weekday[c1-'A'], clock(c2), t);
    return 0;
}