/*
1100. Mars Numbers (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
People on Mars count their numbers with base 13:
Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on 
Mars, respectively.For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, 
kes, hei, elo, syy, lok, mer, jou", respectively.For examples, the number 29 on Earth is called "hel mar" 
on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people 
from these two planets, you are supposed to write a program for mutual translation between Earth and Mars 
number systems.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer 
N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth 
number, or that of Mars.

Output Specification:
For each number, print in a line the corresponding number in the other language.

Sample Input:
4
29
5
elo nov
tam

Sample Output:
hel mar
may
115
13

*/

#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
const char low[13][5] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
const char high[13][5] = {"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int main(){
    int n,a;
    string str,str1,str2;
    map<string,int> low_mp,high_mp;
    for(int i = 0; i < 13; i++){
        str = low[i];
        low_mp[str] = i;
        str = high[i];
        high_mp[str] = i;
    }
    //freopen("in/in.txt","r",stdin);
    cin >> n;getchar();
    for(int i = 0; i < n; i++){
        getline(cin,str);
        if(isdigit(str[0])){
            a = atoi(str.c_str());
            if(a/13>0 && a%13==0){      //整除13
                printf("%s\n",high[a/13]);
            }else if(a/13>0 && a%13!=0){    //不能整除13
                printf("%s %s\n",high[a/13],low[a%13]);
            }else{          //小于13
                printf("%s\n",low[a]);
            }
        }else{
            if(str.size() < 5){
                if(high_mp.find(str) != high_mp.end()) 
                    a = high_mp[str]*13;
                else 
                    a = low_mp[str];
            }else{
                str1 = str.substr(0,3);
                str2 = str.substr(4);
                a = high_mp[str1]*13 + low_mp[str2];
            }
            printf("%d\n",a);
        }
    } 
    return 0;
}