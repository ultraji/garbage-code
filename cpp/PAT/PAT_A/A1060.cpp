/*
1060. Are They Equal (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 
0.123*10^5 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if 
they are treated equal in that machine.

Input Specification:
Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B 
are the two float numbers to be compared. Each float number is non-negative, no greater than 10^100, and that its total digit number is less 
than 100.

Output Specification:
For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" 
(d1>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form. All the terms must be 
separated by a space, with no extra space at the end of a line.
Note: Simple chopping is assumed without rounding.

Sample Input 1:
3 12300 12358.9
Sample Output 1:
YES 0.123*10^5

Sample Input 2:
3 120 128
Sample Output 2:
NO 0.120*10^3 0.128*10^3
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char buff[250];
void mytransform(string &s, int n){
    while(s[0] == '0') s.erase(0,1);                //删除数字首部所有0，直到0~9或'.'
    if(s.find('.') == string::npos) s += '.';       //统一化处理
    int p_pos = s.find('.');             
    int e = p_pos;                                  //指数首先等于'.' 所在的位置
    s.erase(p_pos,1);
    if(e == 0){                                     //如果'.'在字符串首，需要特殊处理,即0.0000123这类情况
        for(; p_pos < s.size() && s[p_pos] == '0';s.erase(p_pos,1)) e--;
    }
    if(s.size() == 0) e = 0;                        //特殊情况 0.000000000
    while(s.size() < n) s += '0';
    s = s.substr(0,n);
    sprintf(buff,"0.%s*10^%d",s.c_str(),e);
    s = buff;
}

int main(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    mytransform(a,n);
    mytransform(b,n);
    if(a == b){
        printf("YES %s", a.c_str());
    }else{
        printf("NO %s %s", a.c_str(), b.c_str());
    }
    return 0;
}