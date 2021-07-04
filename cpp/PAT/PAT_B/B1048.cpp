/*
1048 数字加密 （20 分）
本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以
下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的
数字，若结果为负数，则再加 10。这里令个位为第 1 位。

输入格式：
输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

输出格式：
在一行中输出加密后的结果。

输入样例：
1234567 368782971

输出样例：
3695Q8118
*/

#include <iostream>
#include <algorithm>
using namespace std;

char cc[14] = "0123456789JQK";

int main(){
    int tmp, len;
    string a, b, res;
    char c;
    cin >> a >> b;
    len = a.size() > b.size() ? a.size(): b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a.append(len-a.size(), '0');
    b.append(len-b.size(), '0');
    for(int i = 0; i < len; i++){
        if(i % 2 == 0){
            tmp = (a[i]+b[i]-'0'-'0') % 13;
            c = cc[tmp];
        }else{
            c = b[i] - a[i] + '0';
            c = c < '0'? c+10 : c;
        }
        res.append(1, c);
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}