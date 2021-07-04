/*
1040 有几个PAT （25 分）
字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；
第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。
现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10^5，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT

输出样例：
2
*/

#include <iostream>
using namespace std;

int P[100001], T[100001];

int main(){
    int numP = 0, numT = 0, sum  = 0;
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'P'){
            numP++;
        }
        P[i] = numP;
    }
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'T'){
            numT++;
        }
        T[i] = numT;
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            sum = (sum + P[i] * T[i]) % 1000000007;
        }
    }
    cout << sum << endl;
    return 0;
}