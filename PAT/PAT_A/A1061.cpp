/*
1061. Dating (20)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
Sherlock Holmes received a note with some strange strings: "Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm". It took him 
only a minute to figure out that those strange strings are actually referring to the coded time "Thursday 14:04" -- since the first common 
capital English letter (case sensitive) shared by the first two strings is the 4th capital letter 'D', representing the 4th day in a week; 
the second common character is the 5th capital letter 'E', representing the 14th hour (hence the hours from 0 to 23 in a day are represented 
by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is 's' 
at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.

Input Specification:
Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.

Output Specification:
For each test case, print the decoded time in one line, in the format "DAY HH:MM", where "DAY" is a 3-character abbreviation for the days in a 
week -- that is, "MON" for Monday, "TUE" for Tuesday, "WED" for Wednesday, "THU" for Thursday, "FRI" for Friday, "SAT" for Saturday, and "SUN" for Sunday. It is guaranteed that the result is unique for each case.

Sample Input:
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
Sample Output:
THU 14:04
*/

#include <iostream>
#include <cstring>
#define clock(c) ((c >= 'A' && c <= 'N')?c-'A'+10:c-'0')
using namespace std;
const char weekday[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
char str[4][100];

int main(){
    char c1,c2,*p,*q;
    for(int i = 0; i < 4; i++){
        gets(str[i]);
    }
    for(p = str[0],q = str[1];*p != '\0' && *q != '\0'; p++,q++){
        if(*p >= 'A' && *p <= 'G' && *q == *p ){
            c1 = *p;
            break;
        }
    }
    for(p++, q++; *p != '\0' && *q != '\0'; p++,q++){
        if(((*p >= 'A' && *p <='N')||isdigit(*p))&& *p == *q){
            c2 = *p;
            break;
        }
    }
    int t = 0;
    for(p=str[2],q=str[3]; !(isalpha(*p) && *p == *q); t++,p++,q++);
    printf("%s %02d:%02d", weekday[c1-'A'], clock(c2), t);
    return 0;
}