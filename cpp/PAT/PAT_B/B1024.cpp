/*
1024. 科学计数法 （20 分）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即
数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不
超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03

输出样例 1：
0.00123400

输入样例 2：
-1.2E+10

输出样例 2：
-12000000000
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num, radix, expo;
    cin >> num;
    if(num[0] == '-'){
        cout << '-';
    }
    num.erase(0, 1);
    int e = num.find('E');
    int plot = num.find('.');
    radix = num.substr(0, e);
    expo = num.substr(e+2);
    int cnt = atoi(expo.c_str());
    if(num[e+1] == '-'){
        radix.erase(plot, 1);
        cout << "0.";
        for(int i = 0; i < cnt-1; i++){
            cout << '0';
        }
        cout << radix;
    }else {
        radix.erase(plot, 1);
        int af_plot = radix.size() - 1; // 小数点后的位数
        if(cnt >= af_plot){
            cout << radix.append(cnt - af_plot, '0');
        }else{
            cout << radix.insert(cnt+1, 1, '.');
        }
    }
    return 0;
}
