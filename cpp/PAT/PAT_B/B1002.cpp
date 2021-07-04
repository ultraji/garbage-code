/*
1002. 写出这个数 (20)

读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：
在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789

输出样例：
yi san wu
*/

#include <iostream>
#include <cstring>

#define MAX_SIZE 102

const char* num[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

char str[MAX_SIZE];
int r[MAX_SIZE];

int main()
{
    int k = 0, sum = 0;
    fgets(str, MAX_SIZE, stdin);        // fgets()会获取末尾回车换行符
    for (k = 0; k < strlen(str) - 1; k++){
        sum += str[k] - '0';
    }
    for (k = 0; sum != 0; k++){	        // 从右往左(从个位开始)开始记录结果的每一位数
        r[k] = sum % 10;
        sum /= 10;
    }
    for (k--; k > 0; k--){              // 倒着输出结果
        printf("%s ", num[r[k]]);
    }
    printf("%s", num[r[0]]);
    return 0;
}