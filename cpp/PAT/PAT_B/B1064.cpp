/*
1064 朋友数 （20 分）
如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。例如 
123 和 51 就是朋友数，因为 1+2+3 = 5+1 = 6，而 6 就是它们的朋友证号。给定一些整数，要求你
统计一下它们中有多少个不同的朋友证号。

输入格式：
输入第一行给出正整数 N。随后一行给出 N 个正整数，数字间以空格分隔。题目保证所有数字小于 10^4。

输出格式：
首先第一行输出给定数字中不同的朋友证号的个数；随后一行按递增顺序输出这些朋友证号，数字间隔一个
空格，且行末不得有多余空格。

输入样例：
8
123 899 51 998 27 33 36 12

输出样例：
4
3 6 9 26
*/

#include <iostream>
#include <vector>
using namespace std;

int st[40], n;

int main(){
    string s;
    vector<int> v;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        cin >> s;
        int sum = 0;
        for(int j = 0; j < s.size(); j++){
            sum += s[j] - '0';
        }
        st[sum] = 1;
    }   
    for(int i = 0; i < 40; i++){
        if(st[i] == 1){
            v.push_back(i);
        }
    }
    cout << v.size() << endl;
    for(int i= 0; i < v.size(); i++){
        printf("%d%c", v[i], i==v.size()-1?'\n':' ');
    }
    return 0;
}